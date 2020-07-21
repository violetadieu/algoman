/*
Tag : 구현

문제
JOI군은 문화제에 반 출품물을 선전하기 위해, 포스터를 제작하였다. 이 포스터는 N행 N열의 칸 모양을 하고 있으며, 각 칸은 적, 녹, 청 중 하나의 색으로 칠해져 있다.
포스터의 위에서부터 i번째 행, 왼쪽으로부터 j 열(1<=i<=N, 1<=j<=N)에 있는 칸의 색은, Si,j= `R'의 경우 적색, Si,j= `G'의 경우 녹색, Si,j= `B'의 경우에는 청색으로 칠해져 있다.

그러나, 이 포스터에 반의 모든 사람은 만족해 하지 않았다. 의논을 한 결과, 각 칸의 모양은 바꾸지 않고, 색상을 바꾸어 새로운 포스터를 제작하기로 결정되었다.
새로운 포스터의 위에서부터 i행, 왼쪽에서부터 j 열(1<=i<=N, 1<=j<=N)에 있는 칸의 색은, Ti,j= `R'의 경우 적색, Ti,j= `G'의 경우 녹색, Ti,j= `B'의 경우에는 청색으로 칠해져 있다.

JOI군은 지금부터 포스터에 아래 중 하나의 작업을 반복해나가서, 새로운 포스터를 제작해야 한다.
1.칸을 하나 선택해, 그 칸의 색깔을 마음대로 칠한다.(적, 녹, 청 중 하나)
2.포스터 전체를 90도 '시계방향'으로 회전시킨다. 이 때, 원래 위부터 i행, 왼쪽부터 j열 이었던 칸은, 위부터 j행, 왼쪽부터 번째 열의 칸으로 이동한다.
3.포스터 전체를 90도 '반시계방향'으로 회전시킨다.  이 때, 원래 위부터 i행, 왼쪽부터 j열 이었던 칸은, 위부터 N-i+1행, 왼쪽부터 j번째 열의 칸으로 이동한다.

JOI군은 어떤 작업(3종류 중 하나)이든 1번의 작업에 1분의 시간이 걸린다. JOI군이 만든 포스터, 새로 만드는 포스터의 정보가 주어졌을 때, 
JOI군이 새로 만든 포스터를 만드는 데 최단 시간을 구하는 프로그램을 작성하여라.

제한
1<=N<=500
Si,j는 무조건 R, G, B 중 하나이다.
Ti,j는 무조건 R, G, B 중 하나이다.

입력
입력은 아래의 형식이 표준입력(cin,cout)으로 주어진다.
입출력 예시는 문제참조

출처 : JOI 2020 예선 2 1번문제
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    vector<vector<char>>spin[4];
    int ans=0;
    int N;
    cin>>N;
    vector<vector<char>>S(N);
    vector<vector<char>>T(N);
    for(int i=0;i<N;i++){
            string tmp;
            cin>>tmp;
            for(int p=0;p<tmp.length();p++)
                S[i].push_back(tmp[p]);

    }
    for(int i=0;i<4;i++)
        spin[i].resize(N);
    spin[0]=S;
    for(int i=0;i<N;i++){
            string tmp;
            cin>>tmp;
            for(int p=0;p<tmp.length();p++) {
                T[i].push_back(tmp[p]);
                if(S[i][p]!=tmp[p])
                    ans++;
            }
    }
    //회전 페이즈
    //(n,m)->(n,N-m)

    for(int c=1;c<4;c++){
        int cnt=0;
        for(int i=0;i<N;i++){
            for(int k=0;k<N;k++){
                spin[c][i].push_back(spin[c-1][N-(k+1)][i]);
                if(spin[c][i][k]!=T[i][k])
                    cnt++;
            }
        }
        if(c==1||c==3)
            cnt++;
        else
            cnt+=2;

        if(ans>cnt)
            ans=cnt;
    }
    cout<<ans<<endl;
    //비교 페이즈

    return 0;
}
