#include "includes.h"
#include "defines.h"
#include "proj_api.h"

#include <string.h>
#include <jni.h>
#include <android/log.h>
#include <stdlib.h>

extern "C" {
	jstring Java_com_example_citrongis_MainActivity_getVersion(JNIEnv *env,jobject thiz);
}

jstring Java_com_example_citrongis_MainActivity_getVersion(JNIEnv *env,jobject thiz)
{
	const char *desc = pj_get_release();
	LOGW("%s", desc);
	return (env->NewStringUTF("Hello smal test"));
}

