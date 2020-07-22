/*
Tag : 그리디


문제
Just Oishi Ichigo 농원(이하 JOI 농원)은 동서로 길쭉하기로 유명한 딸기 농원이며, 그 입구는 농원의 가장 서쪽에 있다. 
이 문제에서는 입구부터 동쪽으로 k 미터 나아간 장소를 k라고 부른다.

JOI 농원안에는 N개의 딸기가 있다. 각각 1부터 k까지의 번호가 매겨저 있다. 어떤 딸기도 시각 0에는 푸르다(익지 않은 상태). i번 딸기는 지점 Ai에 
열매를 맺으며, 시각 Ti가 되면 다 익어 붉은 상태가 된다.

딸기는 푸른 상태에서는 수확될 수 없다. 즉, 딸기 i는 시각 Ti가 될때까지 수확이 불가능하다. 당신은 시각 0에 지점 0에 있는 농원의 입구부터 출발해,
최대시속 1m/s로 동서방향으로 이동하면서 딸기를 수확한다. 딸기를 수확하는 데 걸리는 시간은 무시할 수 있다고 한다.

딸기 농원에 대한 정보가 주어졌을 때, 모든 딸기를 붉은 상태(익은 상태)로 수확하고 입구로 돌아오는 데 걸리는 최소 시간을 구하는 프로그램을 작성하여라.

입력
입력은 이하의 형태로 표준 입출력으로 주어진다.(형태는 원문 참조)

출력
모든 딸기를 붉은 상태(익은 상태)로 수확한 후 입구로 돌아오는 데 걸리는 시간의 최솟값를 1줄로 출력.

예제 입출력은 원문을 참조(예제 입출력 해석 필요하면 따로 말씀해주세요)

제한
1<=N<=100000
0<=Ai<1000000000(10의9승)(1<=i<=N)
0<=Ti<=100000000(10의9승)(1<=i<=N)
입력되는 값은 모두 정수이다.

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
