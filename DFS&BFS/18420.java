//백준에 제출할 시, 아래 package 선언문 제거하고 제출해야 함. 같이 제출하면 런타임 에러 발생
package com.company;

import java.util.*;

public class Main {
   static int[] MX={0,0,1,-1};
   static int[] MY={-1,1,0,0};
   static int[][] tenkey=new int[3][3];
   static int[][] cnt=new int[10][10];

    public static void setkey(int x,int y,int start,int goal,int num,boolean[][] visit){
        if(tenkey[x][y]==goal){
            if(cnt[start][goal]==0||cnt[start][goal]>num)
                cnt[start][goal]=num;
            return ;
        }

                for(int q=0;q<4;q++){
                    int new_x=x+MX[q];
                    int new_y=y+MY[q];

                    if(0<=new_x&&new_x<3&&0<=new_y&&new_y<3&&!visit[new_y][new_x]){
                        visit[new_y][new_x]=true;
                        setkey(new_x,new_y,start,goal,num+1,visit);
                        visit[new_y][new_x]=false;
                    }
                }
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int ten=1;
        for(int i=0;i<3;i++){
            for(int k=0;k<3;k++){
                tenkey[i][k]=ten;
                ten++;
            }
        }

        for(int i=0;i<3;i++){
            for(int k=0;k<3;k++){
                for(int p=1;p+tenkey[i][k]<10;p++){
                    boolean[][] visit=new boolean[3][3];
                    setkey(i,k,tenkey[i][k],p+tenkey[i][k],0,visit);
                }
            }
        }
        //0에서 출발 세팅
        for(int i=1;i<10;i++){
            cnt[0][i]=cnt[1][i]+1;
        }
        for(int i=9;i>0;i--){
            for(int k=0;k<10;k++){
                if(i!=k&&cnt[i][k]==0)
                    cnt[i][k]=cnt[k][i];
            }
        }
        int M=sc.nextInt();
        int R=sc.nextInt();
        int ans=-1;
        //자릿수 만큼 더하기(누르는 과정)
        int minimum=100010;
        //숫자를 찾아가는 과정
        for(int i=0;i<10000;i++){
            int tmp=R+M*i;
            String str_tmp=Integer.toString(tmp);
            int len=str_tmp.length();
            int now=cnt[0][str_tmp.charAt(0)-'0'];
            while(tmp>0){
                tmp/=10;
                now++;
            }
            for(int k=0;k<len-1;k++){
                int start=str_tmp.charAt(k)-'0';
                int goal=str_tmp.charAt(k+1)-'0';
                now+=cnt[start][goal];
            }
            if(minimum>now) {
                minimum = now;
            }
        }
        ans=minimum;
        System.out.println(ans);
    }
}
