/*
 * Copyright 2013, The CyanogenMod Project
 *   Shareef Ali
 *   Hashcode
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Custom-Platform_Api.h"

#define LOG_TAG "msm8974_platform"
/*#define LOG_NDEBUG 0*/
#define LOG_NDDEBUG 0

#include <stdlib.h>
#include <dlfcn.h>
#include <cutils/log.h>
#include <cutils/properties.h>
#include <cutils/str_parms.h>
#include <audio_hw.h>
#include <platform_api.h>
#include "platform.h"
#include "audio_extn.h"
#include "voice_extn.h"

snd_device_t custom_platform_get_input_snd_device(void *platform, audio_devices_t out_device)
{
    struct platform_data *my_data = (struct platform_data *)platform;
    struct audio_device *adev = my_data->adev;
    audio_source_t  source = (adev->active_input == NULL) ?
                                AUDIO_SOURCE_DEFAULT : adev->active_input->source;

    audio_mode_t    mode   = adev->mode;
    audio_channel_mask_t channel_mask = (adev->active_input == NULL) ?
                                AUDIO_CHANNEL_IN_MONO : adev->active_input->channel_mask;
    snd_device_t snd_device = SND_DEVICE_NONE;
    int channel_count = popcount(channel_mask);

    if ((out_device != AUDIO_DEVICE_NONE) && ((mode == AUDIO_MODE_IN_CALL) ||
        voice_extn_compress_voip_is_active(adev))) {
        if (adev->voice.tty_mode == TTY_MODE_OFF) {
            if (!(out_device & AUDIO_DEVICE_OUT_EARPIECE &&
                out_device & AUDIO_DEVICE_OUT_WIRED_HEADPHONE)) {
                if (!(out_device & AUDIO_DEVICE_OUT_EARPIECE &&
                    audio_extn_should_use_handset_anc(channel_count))) {
                    if (my_data->fluence_type == FLUENCE_NONE ||
                        my_data->fluence_in_voice_call == false) {
                        snd_device = SND_DEVICE_IN_HANDSET_STEREO_DMIC;
                        return snd_device;
                    }
                }
            }
        }
    }
    return -2;
}
void customInitData(){
    changeAcdbData(SND_DEVICE_OUT_SPEAKER, 15);
    changeAcdbData(SND_DEVICE_OUT_SPEAKER_REVERSE, 15);
    changeAcdbData(SND_DEVICE_OUT_VOICE_SPEAKER, 15);
    changeTableData(SND_DEVICE_IN_HANDSET_STEREO_DMIC, "handset-stereo-dmic-es325");
    changeTableData(SND_DEVICE_IN_SPEAKER_STEREO_DMIC, "speaker-stereo-dmic-es325");
}