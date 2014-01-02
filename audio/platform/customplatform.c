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
    ALOGE("#shareef debug: entered!");

    audio_mode_t    mode   = adev->mode;
    audio_devices_t in_device = ((adev->active_input == NULL) ?
                                    AUDIO_DEVICE_NONE : adev->active_input->device)
                                & ~AUDIO_DEVICE_BIT_IN;
    audio_channel_mask_t channel_mask = (adev->active_input == NULL) ?
                                AUDIO_CHANNEL_IN_MONO : adev->active_input->channel_mask;
    snd_device_t snd_device = SND_DEVICE_NONE;
    int channel_count = popcount(channel_mask);

    ALOGV("%s: enter: out_device(%#x) in_device(%#x)",
          __func__, out_device, in_device);
    if ((out_device != AUDIO_DEVICE_NONE) && ((mode == AUDIO_MODE_IN_CALL) ||
        voice_extn_compress_voip_is_active(adev))) {
        if ((adev->voice.tty_mode != TTY_MODE_OFF) &&
            !voice_extn_compress_voip_is_active(adev)) {
            if (out_device & AUDIO_DEVICE_OUT_WIRED_HEADPHONE ||
                out_device & AUDIO_DEVICE_OUT_WIRED_HEADSET) {
                switch (adev->voice.tty_mode) {
                case TTY_MODE_FULL:
                    snd_device = SND_DEVICE_IN_VOICE_TTY_FULL_HEADSET_MIC;
                    break;
                case TTY_MODE_VCO:
                    snd_device = SND_DEVICE_IN_VOICE_TTY_VCO_HANDSET_MIC;
                    break;
                case TTY_MODE_HCO:
                    snd_device = SND_DEVICE_IN_VOICE_TTY_HCO_HEADSET_MIC;
                    break;
                default:
                    ALOGE("%s: Invalid TTY mode (%#x)",
                          __func__, adev->voice.tty_mode);
                }
                goto exit;
            }
        }
        if (out_device & AUDIO_DEVICE_OUT_EARPIECE ||
            out_device & AUDIO_DEVICE_OUT_WIRED_HEADPHONE) {
            if (out_device & AUDIO_DEVICE_OUT_EARPIECE &&
                audio_extn_should_use_handset_anc(channel_count)) {
                snd_device = SND_DEVICE_IN_AANC_HANDSET_MIC;
            } else if (my_data->fluence_type == FLUENCE_NONE ||
                my_data->fluence_in_voice_call == false) {
                ALOGE("#shareef debug: passed check");
                snd_device = SND_DEVICE_IN_HANDSET_STEREO_DMIC;
                set_echo_reference(adev->mixer, "SLIM_RX");
            } else {
                snd_device = SND_DEVICE_IN_VOICE_DMIC;
                adev->acdb_settings |= DMIC_FLAG;
            }
        } else if (out_device & AUDIO_DEVICE_OUT_WIRED_HEADSET) {
            snd_device = SND_DEVICE_IN_VOICE_HEADSET_MIC;
        } else if (out_device & AUDIO_DEVICE_OUT_ALL_SCO) {
            if (my_data->btsco_sample_rate == SAMPLE_RATE_16KHZ)
                snd_device = SND_DEVICE_IN_BT_SCO_MIC_WB;
            else
                snd_device = SND_DEVICE_IN_BT_SCO_MIC;
        } else if (out_device & AUDIO_DEVICE_OUT_SPEAKER) {
            if (my_data->fluence_type != FLUENCE_NONE &&
                my_data->fluence_in_voice_call &&
                my_data->fluence_in_spkr_mode) {
                if(my_data->fluence_type & FLUENCE_QUAD_MIC) {
                    adev->acdb_settings |= QMIC_FLAG;
                    snd_device = SND_DEVICE_IN_VOICE_SPEAKER_QMIC;
                } else {
                    adev->acdb_settings |= DMIC_FLAG;
                    snd_device = SND_DEVICE_IN_VOICE_SPEAKER_DMIC;
                }
            } else {
                snd_device = SND_DEVICE_IN_SPEAKER_STEREO_DMIC;
            }
        }
    } else if (source == AUDIO_SOURCE_CAMCORDER) {
        if (in_device & AUDIO_DEVICE_IN_BUILTIN_MIC ||
            in_device & AUDIO_DEVICE_IN_BACK_MIC) {
            snd_device = SND_DEVICE_IN_CAMCORDER_MIC;
        }
    } else if (source == AUDIO_SOURCE_VOICE_RECOGNITION) {
        if (in_device & AUDIO_DEVICE_IN_BUILTIN_MIC) {
            if (channel_count == 2) {
                snd_device = SND_DEVICE_IN_VOICE_REC_DMIC_STEREO;
                adev->acdb_settings |= DMIC_FLAG;
            } else if (adev->active_input->enable_ns)
                snd_device = SND_DEVICE_IN_VOICE_REC_MIC_NS;
            else if (my_data->fluence_type != FLUENCE_NONE &&
                     my_data->fluence_in_voice_rec) {
                snd_device = SND_DEVICE_IN_VOICE_REC_DMIC_FLUENCE;
                adev->acdb_settings |= DMIC_FLAG;
            } else {
                snd_device = SND_DEVICE_IN_VOICE_REC_MIC;
            }
        }
    } else if (source == AUDIO_SOURCE_VOICE_COMMUNICATION) {
        if (out_device & AUDIO_DEVICE_OUT_SPEAKER)
            in_device = AUDIO_DEVICE_IN_BACK_MIC;
        if (adev->active_input) {
            if (adev->active_input->enable_aec &&
                    adev->active_input->enable_ns) {
                if (in_device & AUDIO_DEVICE_IN_BACK_MIC) {
                    if (my_data->fluence_type & FLUENCE_DUAL_MIC &&
                       my_data->fluence_in_spkr_mode) {
                        snd_device = SND_DEVICE_IN_SPEAKER_DMIC_AEC_NS;
                        adev->acdb_settings |= DMIC_FLAG;
                    } else
                        snd_device = SND_DEVICE_IN_SPEAKER_MIC_AEC_NS;
                } else if (in_device & AUDIO_DEVICE_IN_BUILTIN_MIC) {
                    if (my_data->fluence_type & FLUENCE_DUAL_MIC) {
                        snd_device = SND_DEVICE_IN_HANDSET_DMIC_AEC_NS;
                        adev->acdb_settings |= DMIC_FLAG;
                    } else
                        snd_device = SND_DEVICE_IN_HANDSET_MIC_AEC_NS;
                } else if (in_device & AUDIO_DEVICE_IN_WIRED_HEADSET) {
                    snd_device = SND_DEVICE_IN_HEADSET_MIC_FLUENCE;
                }
                set_echo_reference(adev->mixer, "SLIM_RX");
            } else if (adev->active_input->enable_aec) {
                if (in_device & AUDIO_DEVICE_IN_BACK_MIC) {
                    if (my_data->fluence_type & FLUENCE_DUAL_MIC) {
                        snd_device = SND_DEVICE_IN_SPEAKER_DMIC_AEC;
                        adev->acdb_settings |= DMIC_FLAG;
                    } else
                        snd_device = SND_DEVICE_IN_SPEAKER_MIC_AEC;
                } else if (in_device & AUDIO_DEVICE_IN_BUILTIN_MIC) {
                    if (my_data->fluence_type & FLUENCE_DUAL_MIC) {
                        snd_device = SND_DEVICE_IN_HANDSET_DMIC_AEC;
                        adev->acdb_settings |= DMIC_FLAG;
                    } else
                        snd_device = SND_DEVICE_IN_HANDSET_MIC_AEC;
                } else if (in_device & AUDIO_DEVICE_IN_WIRED_HEADSET) {
                    snd_device = SND_DEVICE_IN_HEADSET_MIC_FLUENCE;
                }
                set_echo_reference(adev->mixer, "SLIM_RX");
            } else if (adev->active_input->enable_ns) {
                if (in_device & AUDIO_DEVICE_IN_BACK_MIC) {
                    if (my_data->fluence_type & FLUENCE_DUAL_MIC) {
                        snd_device = SND_DEVICE_IN_SPEAKER_DMIC_NS;
                        adev->acdb_settings |= DMIC_FLAG;
                    } else
                        snd_device = SND_DEVICE_IN_SPEAKER_MIC_NS;
                } else if (in_device & AUDIO_DEVICE_IN_BUILTIN_MIC) {
                    if (my_data->fluence_type & FLUENCE_DUAL_MIC) {
                        snd_device = SND_DEVICE_IN_HANDSET_DMIC_NS;
                        adev->acdb_settings |= DMIC_FLAG;
                    } else
                        snd_device = SND_DEVICE_IN_HANDSET_MIC_NS;
                } else if (in_device & AUDIO_DEVICE_IN_WIRED_HEADSET) {
                    snd_device = SND_DEVICE_IN_HEADSET_MIC_FLUENCE;
                }
                set_echo_reference(adev->mixer, "NONE");
            } else
                set_echo_reference(adev->mixer, "NONE");
        }
    } else if (source == AUDIO_SOURCE_MIC) {
        if (in_device & AUDIO_DEVICE_IN_BUILTIN_MIC &&
                channel_count == 1 ) {
            if(my_data->fluence_type & FLUENCE_DUAL_MIC &&
                    my_data->fluence_in_audio_rec)
                snd_device = SND_DEVICE_IN_HANDSET_DMIC;
        }
    } else if (source == AUDIO_SOURCE_FM_RX ||
               source == AUDIO_SOURCE_FM_RX_A2DP) {
        snd_device = SND_DEVICE_IN_CAPTURE_FM;
    } else if (source == AUDIO_SOURCE_DEFAULT) {
        goto exit;
    }


    if (snd_device != SND_DEVICE_NONE) {
        goto exit;
    }

    if (in_device != AUDIO_DEVICE_NONE &&
            !(in_device & AUDIO_DEVICE_IN_VOICE_CALL) &&
            !(in_device & AUDIO_DEVICE_IN_COMMUNICATION)) {
        if (in_device & AUDIO_DEVICE_IN_BUILTIN_MIC) {
            if (audio_extn_ssr_get_enabled() && channel_count == 6)
                snd_device = SND_DEVICE_IN_QUAD_MIC;
            else if (channel_count == 2)
                snd_device = SND_DEVICE_IN_HANDSET_STEREO_DMIC;
            else
                snd_device = SND_DEVICE_IN_HANDSET_MIC;
        } else if (in_device & AUDIO_DEVICE_IN_BACK_MIC) {
            snd_device = SND_DEVICE_IN_SPEAKER_MIC;
        } else if (in_device & AUDIO_DEVICE_IN_WIRED_HEADSET) {
            snd_device = SND_DEVICE_IN_HEADSET_MIC;
        } else if (in_device & AUDIO_DEVICE_IN_BLUETOOTH_SCO_HEADSET) {
            if (my_data->btsco_sample_rate == SAMPLE_RATE_16KHZ)
                snd_device = SND_DEVICE_IN_BT_SCO_MIC_WB;
            else
                snd_device = SND_DEVICE_IN_BT_SCO_MIC;
        } else if (in_device & AUDIO_DEVICE_IN_AUX_DIGITAL) {
            snd_device = SND_DEVICE_IN_HDMI_MIC;
        } else if (in_device & AUDIO_DEVICE_IN_ANLG_DOCK_HEADSET ||
                   in_device & AUDIO_DEVICE_IN_DGTL_DOCK_HEADSET) {
            snd_device = SND_DEVICE_IN_USB_HEADSET_MIC;
        } else if (in_device & AUDIO_DEVICE_IN_FM_RX) {
            snd_device = SND_DEVICE_IN_CAPTURE_FM;
        } else {
            ALOGE("%s: Unknown input device(s) %#x", __func__, in_device);
            ALOGW("%s: Using default handset-mic", __func__);
            snd_device = SND_DEVICE_IN_HANDSET_MIC;
        }
    } else {
        if (out_device & AUDIO_DEVICE_OUT_EARPIECE) {
            snd_device = SND_DEVICE_IN_HANDSET_MIC;
        } else if (out_device & AUDIO_DEVICE_OUT_WIRED_HEADSET) {
            snd_device = SND_DEVICE_IN_HEADSET_MIC;
        } else if (out_device & AUDIO_DEVICE_OUT_SPEAKER) {
            if (channel_count > 1)
                snd_device = SND_DEVICE_IN_SPEAKER_STEREO_DMIC;
            else
                snd_device = SND_DEVICE_IN_SPEAKER_MIC;
        } else if (out_device & AUDIO_DEVICE_OUT_WIRED_HEADPHONE) {
            snd_device = SND_DEVICE_IN_HANDSET_MIC;
        } else if (out_device & AUDIO_DEVICE_OUT_BLUETOOTH_SCO_HEADSET) {
            if (my_data->btsco_sample_rate == SAMPLE_RATE_16KHZ)
                snd_device = SND_DEVICE_IN_BT_SCO_MIC_WB;
            else
                snd_device = SND_DEVICE_IN_BT_SCO_MIC;
        } else if (out_device & AUDIO_DEVICE_OUT_AUX_DIGITAL) {
            snd_device = SND_DEVICE_IN_HDMI_MIC;
        } else if (out_device & AUDIO_DEVICE_OUT_ANLG_DOCK_HEADSET ||
                   out_device & AUDIO_DEVICE_OUT_DGTL_DOCK_HEADSET) {
            snd_device = SND_DEVICE_IN_USB_HEADSET_MIC;
        } else {
            ALOGE("%s: Unknown output device(s) %#x", __func__, out_device);
            ALOGW("%s: Using default handset-mic", __func__);
            snd_device = SND_DEVICE_IN_HANDSET_MIC;
        }
    }
exit:
    ALOGV("%s: exit: in_snd_device(%s)", __func__, ""); //device_table[snd_device]);
    return snd_device;
}
void customInitData(){
    changeAcdbData(SND_DEVICE_OUT_SPEAKER, 15);
    changeAcdbData(SND_DEVICE_OUT_SPEAKER_REVERSE, 15);
    changeAcdbData(SND_DEVICE_OUT_VOICE_SPEAKER, 15);
    changeTableData(SND_DEVICE_IN_HANDSET_STEREO_DMIC, "handset-stereo-dmic-es325");
    changeTableData(SND_DEVICE_IN_SPEAKER_STEREO_DMIC, "speaker-stereo-dmic-es325");
}