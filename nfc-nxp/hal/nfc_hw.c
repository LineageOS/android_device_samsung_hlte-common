/*
 * Copyright (C) 2011 The Android Open Source Project
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
#include <errno.h>
#include <string.h>

#include <hardware/hardware.h>
#include <hardware/nfc.h>

static uint8_t pn544_eedata_settings[][4] = {
    {0xA0, 0x0D, 0x04, 0x06}
    ,{0x03, 0x00, 0x6E, 0xA0}
    ,{0x0D, 0x03, 0x06, 0x48}
    ,{0x18, 0xA0, 0x0D, 0x06}
    ,{0x06, 0x42, 0x00, 0x00}
    ,{0xF6, 0xF6, 0xA0, 0x0D}
    ,{0x06, 0x2C, 0x44, 0x21}
    ,{0x00, 0x02, 0x00, 0xA0}
    ,{0x0D, 0x06, 0x2C, 0x34}
    ,{0x29, 0x03, 0xEC, 0x03}
    ,{0xA0, 0x0D, 0x06, 0x2C}
    ,{0x33, 0x0A, 0x01, 0x00}
    ,{0x50, 0xA0, 0x0D, 0x06}
    ,{0x2C, 0x2D, 0xD4, 0x50}
    ,{0x00, 0x00, 0xA0, 0x0D}
    ,{0x06, 0x2A, 0x42, 0xF8}
    ,{0x30, 0x4F, 0x4F, 0x00}
};

static int pn544_close(hw_device_t *dev) {
    free(dev);

    return 0;
}

/*
 * Generic device handling
 */

static int nfc_open(const hw_module_t* module, const char* name,
        hw_device_t** device) {
    if (strcmp(name, NFC_PN544_CONTROLLER) == 0) {
        nfc_pn544_device_t *dev = calloc(1, sizeof(nfc_pn544_device_t));

        dev->common.tag = HARDWARE_DEVICE_TAG;
        dev->common.version = 0;
        dev->common.module = (struct hw_module_t*) module;
        dev->common.close = pn544_close;

        dev->num_eeprom_settings = sizeof(pn544_eedata_settings) / 4;
        dev->eeprom_settings = (uint8_t*)pn544_eedata_settings;
        dev->linktype = PN544_LINK_TYPE_I2C;
        dev->device_node = "/dev/pn547";
        dev->enable_i2c_workaround = 0;
        *device = (hw_device_t*) dev;
        return 0;
    } else {
        return -EINVAL;
    }
}

static struct hw_module_methods_t nfc_module_methods = {
    .open = nfc_open,
};

struct nfc_module_t HAL_MODULE_INFO_SYM = {
    .common = {
        .tag = HARDWARE_MODULE_TAG,
        .version_major = 1,
        .version_minor = 0,
        .id = NFC_HARDWARE_MODULE_ID,
        .name = "HLTEVZW NFC HW HAL",
        .author = "The Android Open Source Project",
        .methods = &nfc_module_methods,
    },
};
