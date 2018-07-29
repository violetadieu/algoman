#include <iostream>

int main(){
    int DP[101][11]={0,};
    int n=0;
    long sum=0;
    std::cin>>n;

    for(int i=1;i<=9;i++){
        DP[1][i]=1;
    }
    for(int k=2;k<=n;k++) {
        DP[k][0]=DP[k-1][1];
        for (int i = 0; i <= 9; i++) {
            DP[k][i]=(DP[k-1][i+1]+DP[k-1][i-1])%1000000000;
        }
    }

    for(int i=0;i<10;i++){
        sum+=DP[n][i];
    }
    std::cout<<sum%1000000000;
    return 0;
}