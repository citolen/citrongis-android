LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := CitronGIS
LOCAL_SRC_FILES := CitronGIS.cpp

include $(BUILD_SHARED_LIBRARY)
