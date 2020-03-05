#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int DP[101][101]={0,};
    int ma[101][101]={0,};
    DP[1][0]=1;
    for(int p=0;p<puddles.size();p++){
                ma[puddles[p][1]][puddles[p][0]]=(-1);
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(ma[i][k]==(-1))
                DP[i][k]=0;
            else
                DP[i][k]=(DP[i-1][k]+DP[i][k-1])%1000000007;
        }
    }
    answer=DP[n][m];
    return answer;
}
