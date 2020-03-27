#include <iostream>

using namespace std;


void cal(long long  n){
    if(n<=0)
        return ;
    long long ans=0;
    long long c,t;
    long long s=1;
    long long DP[10]={0,};
    while(n>0){
        t=n/(s*10);
        c=n%(s*10);
        for(int i=0;i<10;i++)DP[i] += s*t;
        for(int i=1;i<=c/s;i++)DP[i]+=s;
        DP[(c/s+1)%10]+=c%s;

        n-=9*s;
        s*=10;
    }
    for(int i=0;i<10;i++){
        cout<<DP[i]<<" ";
    }
}

int main(){
    long long  L;
    cin>>L;
    cal(L);
    return 0;
}
