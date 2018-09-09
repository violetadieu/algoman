#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int>coin;
    int DP[10001];
    memset(DP,-1,sizeof(DP));
    int n,k;
    int result=0;
    cin>>n>>k;
    coin.resize(n);
    for(int i=0;i<n;i++){
        cin>>coin[i];
        if(coin[i]>10000)
            coin[i]=1;
    }
    sort(coin.begin(),coin.end());
    DP[0]=0;
    for(int i=1;i<=k;i++){
        DP[i]=9999;
        for(int p=0;p<n;p++){
            if(i>=coin[p]&&DP[i-coin[p]]!=9999){
                DP[i]=min(DP[i],DP[i-coin[p]]+1);
            }
        }
    }
    cout<<DP[k];
    return 0;
}