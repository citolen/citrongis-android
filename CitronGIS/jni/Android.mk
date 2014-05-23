LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := CitronGIS

## Includes path
LOCAL_C_INCLUDES += $(LOCAL_PATH)/Headers/
LOCAL_C_INCLUDES += /usr/local/include/

## Sources files
LOCAL_SRC_FILES := Sources/main.cpp

## Libraries
LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM
LOCAL_STATIC_LIBRARIES := android_native_app_glue
LOCAL_STATIC_LIBRARIES += clibs
LOCAL_STATIC_LIBRARIES += /usr/local/lib/libproj



include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)
