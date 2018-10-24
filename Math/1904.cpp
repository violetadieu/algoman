#include<iostream>

using namespace std;

int main(){
    int n;
    int DP[1000001]={0,};
    cin>>n;
    DP[0]=0;
    DP[1]=1;//1
    DP[2]=2;
    for(int i=3;i<=n;i++){
        DP[i]=DP[i-2]+DP[i-1];
        DP[i]%=15746;
    }
    cout<<DP[n];
    return 0;
}