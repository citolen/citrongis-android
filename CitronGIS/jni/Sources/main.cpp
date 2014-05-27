#include "includes.h"
#include "defines.h"
#include "proj_api.h"

/*void android_main(struct android_app* state) {
	app_dummy();

	LOGW("APPLICATION STARTED");
}*/

#include <string.h>
#include <jni.h>

jstring Java_com_example_citrongis_MainActivity_getVersion(JNIEnv *env,jobject thiz)
{
    const char *desc = pj_get_release();
    LOGW("%s", desc);
}
