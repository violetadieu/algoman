//왜 레벨3인지 모르겟음 너무쉬움
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
    long long DP[2001]={0,};
    DP[1]=1;
    DP[2]=2;
    for(int i=3;i<=n;i++){
        DP[i]=DP[i-1]%1234567+DP[i-2]%1234567;
        DP[i]%=1234567;
    }
    return DP[n];
}
