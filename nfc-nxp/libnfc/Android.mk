LOCAL_PATH:= $(call my-dir)

#
# libnfc wrapper
#

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= src/wrapper.c

LOCAL_CFLAGS += -I$(LOCAL_PATH)/inc
LOCAL_CFLAGS += -I$(LOCAL_PATH)/src

LOCAL_SHARED_LIBRARIES:= libdl libm libc libcutils libhardware libnfc_ndef
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)
LOCAL_MODULE:= libnfc
LOCAL_MODULE_TAGS := eng debug
LOCAL_PRELINK_MODULE := false

include $(BUILD_SHARED_LIBRARY)

#
# libnfc_ndef
#

include $(CLEAR_VARS)

LOCAL_SRC_FILES += src/phFriNfc_NdefRecord.c

LOCAL_CFLAGS += -I$(LOCAL_PATH)/inc
LOCAL_CFLAGS += -I$(LOCAL_PATH)/src

LOCAL_MODULE:= libnfc_ndef
LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES := libcutils liblog

include $(BUILD_SHARED_LIBRARY)
