#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int DP[1000001]={0,};
    DP[0]=0;
    DP[1]=1;
    for(int i=2;i<=n;i++){
        DP[i]=(DP[i-1]+DP[i-2])%1234567;
    }
    answer=DP[n];
    return answer;
}
