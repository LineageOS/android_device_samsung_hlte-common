/*
 * Copyright Shareef Ali @ CyanogenMod project
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

#ifndef QCOM_AUDIO_PLATFORM_API_H_Cus
#define QCOM_AUDIO_PLATFORM_API_H_Cus
#include <pthread.h>
#include <audio_hw.h>

snd_device_t custom_platform_get_input_snd_device(void *platform, audio_devices_t out_device);
#endif // QCOM_AUDIO_PLATFORM_API_H
