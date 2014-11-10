#include "AppDelegate.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <android/log.h>

#include "cocos2d.h"

#define  LOG_TAG    "main"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

using namespace cocos2d;

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_javascript_Testwrap
 * Method:    testfunc
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jstring JNICALL Java_org_javascript_Testwrap_testfunc(JNIEnv *env, jclass obj, jstring str) {
	const char *nativeString = env->GetStringUTFChars(str, 0);
	LOGD("-> %s", nativeString);

	jclass clazz = env->FindClass("org/javascript/Testwrap");
	jmethodID func = env->GetMethodID(clazz, "printSomething", "(Ljava/lang/String;)Ljava/lang/String;");
	jobject result = env->CallObjectMethod(obj, func, str);

	return env->NewStringUTF("Hello from JNI !");
}

#ifdef __cplusplus
}
#endif


void cocos_android_app_init (JNIEnv* env, jobject thiz) {
    LOGD("cocos_android_app_init");
    AppDelegate *pAppDelegate = new AppDelegate();
}
