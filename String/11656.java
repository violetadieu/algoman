//백준에 제출할 시, 아래 package 선언문 제거하고 제출해야 함. 같이 제출하면 런타임 에러 발생
package com.company;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        List<String>list=new ArrayList<String>();
        String tmp="";
        for(int i=0;i<s.length();i++){
            tmp=s.substring(i,s.length());
            list.add(tmp);
        }
        Collections.sort(list);
        for(int i=0;i<list.size();i++){
            System.out.println(list.get(i));
        }
    }
}
