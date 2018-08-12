#include <iostream>
using namespace std;

int main(){

    int N,M,K;
    cin>>N>>M;

    int value=0;
    int dp[301][301]={0}; //(0,0)에서 (n,m)까지의 합
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            scanf("%d",&value);
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+value;
        }

    cin>>K;
    int sum=0;
    int x1,x2,y1,y2;
    for(int testCase=0;testCase<K;testCase++){
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);

        sum=dp[y2][x2]-dp[y2][x1-1]-dp[y1-1][x2]+dp[y1-1][x1-1];
        printf("%d\n",sum);
    }

    return 0;
}
