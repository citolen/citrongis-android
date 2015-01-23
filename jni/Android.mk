LOCAL_PATH := $(call my-dir)

# Build Proj4 module
include $(CLEAR_VARS)
LOCAL_MODULE:= proj
LOCAL_LDLIBS:= -lm
LOCAL_SRC_FILES := libs/proj4/libproj.so
include $(PREBUILT_SHARED_LIBRARY)

# Build Cocos2d module
include $(CLEAR_VARS)

LOCAL_MODULE := cpp_empty_test_shared

LOCAL_MODULE_FILENAME := libcpp_empty_test

# Sources
LOCAL_SRC_FILES := 	Core/main.cpp \
                   	Core/AppDelegate.cpp \
                   	Core/HelloWorldScene.cpp \
					Classes/Geometry/Point.cpp \
					Classes/Geometry/BoundingBox.cpp \
					Classes/Geometry/Vector2.cpp \
					Classes/Geometry/Vector3.cpp \
					Classes/Utils/Comparison.cpp \
					Classes/Utils/Intersection.cpp \
					Classes/Helpers/CoordinatesHelper.cpp \
					Classes/Helpers/ProjectionsHelper.cpp
                   
# Includes directories
LOCAL_C_INCLUDES := $(LOCAL_PATH)/Classes \
					$(LOCAL_PATH)/Core \
					$(COCOS_X_ROOT)/extensions \
					$(LOCAL_PATH)/libs/proj4

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static clibs
LOCAL_SHARED_LIBRARIES += proj

include $(BUILD_SHARED_LIBRARY)


# Test if COCOS_X_ROOT env variable exists
COCOS_PATH  := $(COCOS_X_ROOT)
ifndef COCOS_PATH
$(warning Missing COCOS_X_ROOT environnement variable)
endif

# import cocos modules
$(call import-add-path,$(COCOS_X_ROOT)/cocos)
$(call import-add-path,$(COCOS_X_ROOT)/)
$(call import-add-path,$(COCOS_X_ROOT)/external)

$(call import-module,.)
$(call import-module,audio/android)