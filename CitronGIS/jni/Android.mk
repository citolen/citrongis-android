LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := CitronGIS

## Includes path
LOCAL_C_INCLUDES += $(LOCAL_PATH)/Headers/
LOCAL_C_INCLUDES += /usr/local/include/

## Sources files
LOCAL_SRC_FILES :=	Sources/main.cpp \
					
LOCAL_SRC_FILES	+=	Sources/Geometry/BoundingBox.cpp \
					Sources/Geometry/Point.cpp \
					Sources/Geometry/Vector2.cpp \
					Sources/Geometry/Vector3.cpp \

LOCAL_SRC_FILES	+=	Sources/Utils/Comparison.cpp \
					Sources/Utils/Intersection.cpp \

LOCAL_SRC_FILES	+=	Sources/Helpers/CoordinatesHelper.cpp \
					Sources/Helpers/ProjectionsHelper.cpp \
					
LOCAL_SRC_FILES	+=	Sources/System/Viewport.cpp \

## Libraries
LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM -L$(LOCAL_PATH)/libs -lproj
LOCAL_STATIC_LIBRARIES := android_native_app_glue
LOCAL_STATIC_LIBRARIES += clibs

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)