/*
Tag : Dynamic Programming

문제
JOI군은 처음에 1이상 N이사의 어떤 정수를 갖고 있다. JOI군은 이하의 조작을 0회이상 시행했더니, 갖고 있는 정수가 N이 되었다.
 - 갖고있는 정수를 십진법으로 표시하였을떄 각 자리의 합을, 갖고 있는 정수에 더한다.
 N이 주어졌을때, JOI군이 처음에 갖고 있을 가능성이 있는 정수의 개수를 구하는 프로그램을 작성하여라.

입력
입력은 아래의 형태로 표준입력으로 주어진다.
N

출력
JOI군이 처음에 가지고 있을 가능성이 있는 정수의 개수를 1줄로 출력하여라.

제한
1<=N<=1000000
N은 정수이다.

예제 입출력은 원문을 참조.(출력에 대한 설명의 해석이 필요하시면 문의해주세요)

*/
//제출 시 아래 패키지 선언문 제거하지 않으면 런타임 오류 발생
package com.company;

import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] DP=new int[N+1];
        for(int i=1;i<N;i++){
            int start=i;
            String tmp=Integer.toString(start);
            for(int k=0;k<tmp.length();k++){
                start+=tmp.charAt(k)-'0';
            }
            if(start<=N)
                DP[start]+=DP[i]+1;
        }
        System.out.print(DP[N]+1);
    }
}
