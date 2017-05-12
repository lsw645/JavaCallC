package com.lxw.javacallc;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextView tv;
    private Jni mJni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tv = (TextView) findViewById(R.id.tv_content);
        mJni = new Jni();
    }

    public void onAddClick(View view) {
         int[] array={10,20,30,40};
         int []a=   mJni.increaeArrayElss(array);
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<a.length;i++){
            sb.append("array["+i+"]的值为："+a[i]+"\n");
        }
        tv.setText(sb.toString());
    }

    public void onCalculateClick(View view) {
        int result = mJni.add(10, 20);
        tv.setText(String.valueOf(result));
    }

    public void onStringClick(View view) {
        String s = "I come from java";
        s=mJni.addString(s);
        tv.setText(s);
    }
    
    public void onVerifyClick(View view) {
        String pwd = "1234567";
       int s= mJni.vetifyPassword(pwd);
        tv.setText("返回值为："+s);
    }
}
