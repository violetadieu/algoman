#include <iostream>
using namespace std;

int main(){
    int n,k;
    int DP[1001]={0,};
    cin>>n>>k;
    if(k==0){
        cout<<"0";
        return 0;
    }
    DP[0]=0;
    DP[1]=1;
    for(int i=2;i<1001;i++){
        DP[i]=DP[i-1]*i;
    }
    int tmp=DP[n]/(DP[k]*DP[n-k]);
    cout<<tmp;
    return 0;
}