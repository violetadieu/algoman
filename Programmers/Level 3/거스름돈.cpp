#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int DP[100001]={0,};
    sort(money.begin(),money.end());
    //만들수 있는 최소 금액==제일 작은 단위
    int start=money[0];
    DP[0]=1;
    for(int i=start;i<=n;i+=money[0])
        DP[i]=1;
    for(int j=1;j<money.size();j++){
        for(int i=0;i<=n;i++){
            if(i>=money[j]){
                DP[i]+=DP[i-money[j]]%1000000007;
            }
        }
    }
    return DP[n];
}