#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k;
    vector<int>coin;
    int DP[101][10001]={0,};
    cin>>n>>k;
    coin.resize(n);
    for(int i=1;i<=n;i++){
        cin>>coin[i];
    }
    for(int i=1;i<=k;i++){
        DP[i][0]=1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= coin[i]) {
                DP[i][j] = DP[i - 1][j] + DP[i][j - coin[i]];
            }
            else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }
    cout<<DP[n][k];
    return 0;
}