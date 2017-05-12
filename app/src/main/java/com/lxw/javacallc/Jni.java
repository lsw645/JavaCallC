package com.lxw.javacallc;

import junit.framework.Test;

/**
 * <pre>
 *     author : lxw
 *     e-mail : lsw@tairunmh.com
 *     time   : 2017/05/11
 *     desc   :
 * </pre>
 */

public class Jni {
    static {
        System.loadLibrary("Test");

    }

    public native  int add(int x,int y);

    public native String addString(String str);

    public native int[] increaeArrayElss(int[] array);

    public native int vetifyPassword(String pwd);



}
