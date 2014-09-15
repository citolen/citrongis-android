LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cpp_empty_test_shared

LOCAL_MODULE_FILENAME := libcpp_empty_test

LOCAL_SRC_FILES := main.cpp \
                   Classes/AppDelegate.cpp \
                   Classes/HelloWorldScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static

include $(BUILD_SHARED_LIBRARY)

# Test if COCOS2DX env variable exists
COCOS_PATH  := $(COCOS2DX)
ifndef COCOS_PATH
$(warning Missing COCOS2DX environnement variable)
endif

# import cocos modules
$(call import-add-path,$(COCOS2DX)/cocos)
$(call import-add-path,$(COCOS2DX)/external)

$(call import-module,.)
$(call import-module,audio/android)
