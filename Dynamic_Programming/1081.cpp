//어려웠음
#include <iostream>

using namespace std;


long long  cal(long long  n){
    if(n<=0)
        return 0;
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
    for(int i=1;i<10;i++){
        ans+=i*DP[i];
    }
    return ans;
}

int main(){
    long long  L;
    long long  U;
    cin>>L>>U;
    cout<<cal(U)-cal(L-1)<<endl;
    return 0;
}
