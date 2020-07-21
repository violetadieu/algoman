/*
Tag : 그리디

*/
//백준에 제출할 시, 아래 package 선언문을 제거하고 제출해야 함. 같이 제출하면 런타임 에러 발생
package com.company;

import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int ans=0;
        int N=sc.nextInt();
        int max_range=0;
        int max_ichigo=0;

        for(int i=0;i<N;i++){
            int range=sc.nextInt();
            int ichigo=sc.nextInt();
            ans=Math.max(ans,Math.max(range,ichigo)+range);
        }


        System.out.println(ans);
    }
}
