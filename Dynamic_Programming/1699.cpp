#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int DP[100001]={0,};

int min(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}

int main(){
    int N;
    cin>>N;
    DP[1]=1;//1=pow(1,1)
    for(int i=0;i<100001;i++){
        DP[i]=i;
    }
    for(int i=2;i<100001;i++){
        for(int j=2;j*j<=i;j++){
            DP[i]=min(DP[i],DP[i-j*j]+1);
        }
    }
    cout<<DP[N];

    return 0;
}
