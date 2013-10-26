# Copyright (C) 2009 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#

# inherit from common msm8960
-include device/samsung/msm8960-common/BoardConfigCommon.mk

TARGET_SPECIFIC_HEADER_PATH := device/samsung/hltexx/include


# overrides  msm8960
TARGET_BOARD_PLATFORM := msm8974
TARGET_BOARD_PLATFORM_GPU := qcom-adreno330
TARGET_BOOTLOADER_BOARD_NAME := MSM8974

# Krait optimizations
TARGET_USE_KRAIT_BIONIC_OPTIMIZATION := true
TARGET_USE_KRAIT_PLD_SET      := true
TARGET_KRAIT_BIONIC_PLDOFFS   := 10
TARGET_KRAIT_BIONIC_PLDTHRESH := 10
TARGET_KRAIT_BIONIC_BBTHRESH  := 64
TARGET_KRAIT_BIONIC_PLDSIZE   := 64

# Kernel Configs
TARGET_KERNEL_SOURCE := kernel/samsung/hlte
TARGET_KERNEL_CONFIG := msm8974_sec_defconfig
TARGET_KERNEL_SELINUX_CONFIG := selinux_defconfig

# Kernel
BOARD_KERNEL_CMDLINE := console=null androidboot.hardware=qcom user_debug=31 msm_rtb.filter=0x3F
BOARD_KERNEL_BASE := 0x00000000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x02000000 --dt device/samsung/hltexx/dtb.img --tags_offset 0x01e00000
BOARD_KERNEL_SEPARATED_DT := true

# Graphics
TARGET_USES_QCOM_BSP := true
COMMON_GLOBAL_CFLAGS += -DQCOM_BSP
BOARD_EGL_CFG := device/samsung/hltexx/egl.cfg
TARGET_QCOM_DISPLAY_VARIANT := mdss

# Recovery
TARGET_RECOVERY_PIXEL_FORMAT := "RGBX_8888"
BOARD_CUSTOM_RECOVERY_KEYMAPPING := ../../device/samsung/hltexx/recovery/recovery_keys.c
BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_23x41.h\"
BOARD_USES_MMCUTILS := true
BOARD_HAS_LARGE_FILESYSTEM := true
BOARD_HAS_NO_MISC_PARTITION := true
BOARD_HAS_NO_SELECT_BUTTON := true
TARGET_RECOVERY_FSTAB := device/samsung/hltexx/rootdir/etc/fstab.qcom

TARGET_USERIMAGES_USE_EXT4 := true
BOARD_BOOTIMAGE_PARTITION_SIZE := 11534336
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 13631488
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1572864000
BOARD_USERDATAIMAGE_PARTITION_SIZE := 28651290624
BOARD_FLASH_BLOCK_SIZE := 131072

# bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := device/samsung/hltexx/bluetooth
BOARD_BLUEDROID_VENDOR_CONF := device/samsung/hltexx/bluetooth/vnd_hltexx.txt
BOARD_BLUETOOTH_USES_HCIATTACH_PROPERTY := false

# NFC
BOARD_NFC_HAL_SUFFIX := msm8974

# Disable initlogo, Samsungs framebuffer is weird
TARGET_NO_INITLOGO := true

# Use seperate speakerphone device
BOARD_USES_SEPERATED_VOICE_SPEAKER := true

# Use USB Dock Audio
BOARD_HAVE_DOCK_USBAUDIO := true

# Use the ES325 dual mic feature
BOARD_HAVE_AUDIENCE_ES325_2MIC := true

# Disable Fluence
BOARD_USES_FLUENCE_INCALL := false

# Samsung's nonstandard csd-client
BOARD_HAVE_NEW_QCOM_CSDCLIENT := true

# Use seperate devices for VOIP
BOARD_USES_SEPERATED_VOIP := true

# Use seperate devices for 3-pole headse
BOARD_USES_SEPERATED_HEADSET_MIC := true

#GPS
BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE := $(TARGET_BOARD_PLATFORM)
TARGET_NO_RPC := true
BOARD_HAVE_NEW_QC_GPS :=

#BOARD_USE_SAMSUNG_SEPARATEDSTREAM := true
#BOARD_USES_LIBMEDIA_WITH_AUDIOPARAMETER := true
#TARGET_PROVIDES_LIBAUDIO := true

# SELinux
BOARD_SEPOLICY_DIRS += \
        device/samsung/hltexx/sepolicy

BOARD_SEPOLICY_UNION += \
	file_contexts \
	property_contexts \
	te_macros \
	bluetooth_loader.te \
	bridge.te \
	camera.te \
	conn_init.te \
	device.te \
	dhcp.te \
	domain.te \
	drmserver.te \
	file.te \
	init.te \
	kickstart.te \
	mediaserver.te \
	mpdecision.te \
	netmgrd.te \
	property.te \
	qmux.te \
	rild.te \
	rmt.te \
	sensors.te \
	surfaceflinger.te \
	system.te \
	tee.te \
	thermald.te \
	ueventd.te \
	wpa_supplicant.te
    
    
# Use retire fence from MDP driver
TARGET_DISPLAY_USE_RETIRE_FENCE :=
WIFI_DRIVER_FW_PATH_P2P     := 
