#include <jni.h>
#include <string>
#include <curl.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_salton123_easemob_Facade_createAccount(
        JNIEnv *env, jobject thiz,
        jstring username, jstring password
) {

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_salton123_easemob_Facade_version(JNIEnv *env, jobject thiz) {
    std::string version = "1.0.0-snapshot";
    return env->NewStringUTF(version.c_str());
}