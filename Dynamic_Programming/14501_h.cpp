#include<iostream>
#include<vector>
using namespace std;
int DP[16]={0,};
int P[16]={0,};
int T[16]={0,};
int ma(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>T[i]>>P[i];
        DP[i]=P[i];
    }
    for(int i=2;i<16;i++){
        for(int p=1;p<i;p++){
            if(i-p>=T[p])
                DP[i]=ma(DP[p]+P[i],DP[i]);
        }
    }
    int result=0;
    for(int i=1;i<=N;i++){
        if(i+T[i]<=N+1&&DP[i]>result)
            result=DP[i];
    }
    cout<<result;
    return 0;
}