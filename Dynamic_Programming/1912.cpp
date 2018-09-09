#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,Max;
    int DP[100001]={0,};
    vector<int>num;
    cin>>n;
    num.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<=n;i++){
        if(DP[i-1]+num[i]>num[i])
            DP[i]=DP[i-1]+num[i];
        else
            DP[i]=num[i];
    }
    Max=DP[1];
    for(int i=1;i<=n;i++){
        if(DP[i]>Max)
            Max=DP[i];
    }
    cout<<Max;
    return 0;
}