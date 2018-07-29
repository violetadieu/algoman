#include <iostream>

using namespace std;

int max(int x,int y);

int main(){
    int DP[500][500]={0,};
    int n=0;
    int M=0;
    cin>>n;//삼각형의 높이

    for(int k=0;k<n;k++) {
        for (int i = 0; i <= k; i++){
            cin>>DP[k][i];
        }
    }

    for(int k=1;k<n;k++) {
        for (int i = 0; i <=k; i++){
            if(i==0){
                DP[k][i]+=DP[k-1][i];
            }
            else if(i==k){
                DP[k][i]+=DP[k-1][i-1];
            }
            else
                DP[k][i]+=max(DP[k-1][i],DP[k-1][i-1]);

            if(M<DP[k][i])
                M=DP[k][i];
        }
    }

    cout<< M;

    return 0;
}

int max(int x,int y){
    if(x>y||x==y)
        return x;
    else
        return y;

}