#include <jni.h>
#include <string>
#include <curl.h>


extern "C"
JNIEXPORT jstring JNICALL
Java_com_salton123_easemob_Facade_version(JNIEnv *env, jobject thiz) {
    std::string version = "1.0.0-snapshot";
    return env->NewStringUTF(version.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_salton123_easemob_Facade_createAccount(
        JNIEnv *env, jobject thiz,
        jstring username, jstring password
) {
    int retcode = 0;
    CURL *curl = curl_easy_init();
    CURLcode res = CURLE_FAILED_INIT;
    curl_easy_setopt(curl, CURLOPT_URL, "http://a1.easemob.com/newsalton/reprint-android/token");
    // 设置为Post
//    {
//        "grant_type": "client_credentials",
//                "client_id": "YXA6xAckRnEPRJSbUij0UVDR5Q",
//                "client_secret": "YXA6JIba-SD4yKMmEW68-w1s7z0kPaA"
//    }
    char *json = "{"
                 "  \"grant_type\": \"client_credentials\","
                 "  \"client_id\": \"YXA6xAckRnEPRJSbUij0UVDR5Q\","
                 "  \"client_secret\": \"YXA6JIba-SD4yKMmEW68-w1s7z0kPaA\""
                 "}";
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, -1L);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
//    if (res != CURLE_OK) {
////        size_t len = strlen(errbuf);
//        fprintf(stderr, "\nlibcurl: (%d) ", res);
////        if (len)
////            fprintf(stderr, "%s%s", errbuf, ((errbuf[len - 1] != '\n') ? "\n" : ""));
////        fprintf(stderr, "%s\n\n", curl_easy_strerror(res));
////        goto cleanup;
//    }
//    fprintf(stderr, "\nlibcurl: (%d) ", res);
//    retcode = 1;

//    cleanup:
//    curl_slist_free_all(headers);
//    curl_easy_cleanup(curl);
//    cJSON_Delete(root);
//    free(json);
//    return retcode;
}

