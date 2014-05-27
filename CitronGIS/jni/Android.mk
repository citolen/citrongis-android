LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:= proj
LOCAL_SRC_FILES := libs/libproj.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := CitronGIS

## Includes path
LOCAL_C_INCLUDES += $(LOCAL_PATH)/Headers/
LOCAL_C_INCLUDES += /usr/local/include/

## Sources files
LOCAL_SRC_FILES :=	Sources/main.cpp \
					Sources/Geometry/Point.cpp


## Libraries
LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM
LOCAL_STATIC_LIBRARIES := android_native_app_glue
LOCAL_STATIC_LIBRARIES += clibs
LOCAL_SHARED_LIBRARIES := proj
##LOCAL_LDFLAGS := -Wl,-soname,. -Wl,-soname,/data/libs
##LOCAL_LDFLAGS := -Wl,-soname,$(LOCAL_PATH)/libs
include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)
