#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int n) {
    int DP[5001]={0,};
    DP[2]=3;
    for(int i=4;i<=n;i+=2){
        DP[i]=(3*DP[i-2])%1000000007;
        DP[i]+=2;
        for(int k=0;k<i-2;k+=2)
            DP[i]+=(2*DP[k])%1000000007;
    }
    return DP[n];
}

int main() {
   int n=4;
    cout<< solution(n)<< endl;

    return 0;
}
