LOCAL_PATH := $(call my-dir)

ifneq ($(filter hlte hltetmo hltespr hlteusc hltevzw,$(TARGET_DEVICE)),)

# HAL module implemenation stored in
# hw/<POWERS_HARDWARE_MODULE_ID>.<ro.hardware>.so
include $(CLEAR_VARS)

LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR_SHARED_LIBRARIES)/hw
LOCAL_SHARED_LIBRARIES := liblog libcutils libdl
LOCAL_SRC_FILES := power.c metadata-parser.c utils.c list.c hint-data.c power-8974.c power_ext.c

ifeq ($(TARGET_USES_INTERACTION_BOOST),true)
    LOCAL_CFLAGS += -DINTERACTION_BOOST
endif

LOCAL_CFLAGS += -DSET_INTERACTIVE_EXT

LOCAL_MODULE := power.msm8974
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

endif