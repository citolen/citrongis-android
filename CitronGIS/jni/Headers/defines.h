#ifndef __DEFINES_H__
#define __DEFINES_H__

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-activity", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "native-activity", __VA_ARGS__))
#define LOGA(...) ((void)__android_log_print(ANDROID_LOG_FATAL, "native-activity", __VA_ARGS__))

#endif
