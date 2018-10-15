#include <iostream>

using namespace std;

int maximum( int a, int b, int c )
{
    int max = ( a < b ) ? b : a;
    return ( ( max < c ) ? c : max );
}

int main(){
    int N,M;
    int candy[1001][1001]={0,};
    int DP[1001][1001]={0,};
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int k=0;k<M;k++){
            cin>>candy[i][k];
            DP[i][k]=candy[i][k];
        }
    }
    for(int i=0;i<N;i++){
        for(int k=0;k<M;k++){
            if(i==0&&k==0)//시작지점은
                continue;//스킵
            if(i==0)//맨 윗줄
                DP[i][k]=max(DP[i][k],DP[i][k]+DP[i][k-1]);
            else if(k==0)//맨 왼쪽줄
                DP[i][k]=max(DP[i][k],DP[i][k]+DP[i-1][k]);
            else{//그 외(대각선은 무조건 최댓값이 될 수 없음)
                DP[i][k]=maximum(DP[i][k],DP[i][k]+DP[i][k-1],DP[i][k]+DP[i-1][k]);
            }
        }
    }
    cout<<DP[N-1][M-1];
    return 0;
}