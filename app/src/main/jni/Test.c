//
// Created by lsw on 2017/5/11.
//
#include"com_lxw_javacallc_Jni.h"
#include <string.h>

char* _JString2CStr(JNIEnv* env,jstring jstr){
    char* rtn=NULL;
    jclass clsstring =(*env)->FindClass(env,"java/lang/String");
    jstring strencode =(*env)->NewStringUTF(env,"GB2312");
    jmethodID mid=(*env)->GetMethodID(env,clsstring,"getBytes","(Ljava/lang/String;)[B");
    jbyteArray barr =(jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode);
    jsize alen=(*env)->GetArrayLength(env,barr);
    jbyte* ba=(*env)->GetByteArrayElements(env,barr,JNI_FALSE);
    if(alen >0){
        rtn =(char*)malloc(alen+1);
        memcpy(rtn,ba,alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env,barr,ba,0);
    return rtn;
}

 jint  Java_com_lxw_javacallc_Jni_add(JNIEnv *env, jobject job, jint x, jint y){
            return x+y;
  }

jstring  Java_com_lxw_javacallc_Jni_addString(JNIEnv *env, jobject job, jstring string){

    char* result=_JString2CStr(env,string);
    char* text="  add I come from C";
    strcat(result,text);
    return (*env)->NewStringUTF(env,result);
 };

jintArray  Java_com_lxw_javacallc_Jni_increaeArrayElss(JNIEnv *env, jobject object, jintArray array){


    jsize size =(*env)->GetArrayLength(env,array);
    jint* intArray=(*env)->GetIntArrayElements(env,array,JNI_FALSE);
    int i=0;
    for(i=0;i<size;i++){
        *(intArray+ i)  +=100;
    }
    return array;
};

jint  Java_com_lxw_javacallc_Jni_vetifyPassword(JNIEnv *env, jobject object, jstring string){
        char* orgin ="123456";
    char* fromUser=_JString2CStr(env,string);
    int code =strcmp(orgin,fromUser);
    if(code ==0){
        return 400;
    }else{
        return 200;
    }
};

