#include<iostream>
using namespace std;

int main(){
    int DP[1000]={0,};
    DP[1]=1;
    DP[2]=2;
    int n=0;
    cin>>n;//n은 타일의 길이

    for(int i=3;i<=n;i++){
        DP[i]=DP[i-1]+DP[i-2];
        DP[i]=DP[i]%10007;
    }
    cout<<DP[n];
}