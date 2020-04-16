//백준에 제출할 시, 아래 package 선언문 제거하고 제출해야 함. 같이 제출하면 런타임 에러 발생
package com.company;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int ans=0;

        Set<String>not=new HashSet<>();
        ArrayList<String>not_heard_see=new ArrayList<String>();



        for(int i=0;i<n;i++){
            String tmp=sc.next();
            not.add(tmp);
        }

        for(int i=0;i<m;i++){
            String tmp=sc.next();
            boolean t=not.contains(tmp);
            if(t) {
                not_heard_see.add(tmp);
                ans++;
            }
        }

        Collections.sort(not_heard_see);
        System.out.println(ans);
        for(int i=0;i<not_heard_see.size();i++) {
            System.out.println(not_heard_see.get(i));
        }
    }
}
