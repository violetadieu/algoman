//백준에 제출할 시, 아래 package 선언문 제거하고 제출해야 함. 같이 제출하면 런타임 에러 발생
package com.company;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int ans=0;
        String[] words=new String[N];

        for(int i=0;i<N;i++) {
            boolean[] chk=new boolean[26];
            words[i] = sc.next();
            int len=words[i].length();
            for(int k=0;k<len;k++){
                char now=words[i].charAt(k);
                if(chk[(int)now%26])
                    break;

                if(k!=len-1){
                    if(now!=words[i].charAt(k+1))
                        chk[(int)now%26]=true;
                    }
                else{
                    if(!chk[(int)now%26])
                        ans++;
                }
            }
        }

        System.out.println(ans);
    }
}
