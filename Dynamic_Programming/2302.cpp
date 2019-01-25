#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    int DP[41]={0,};
    int result=1;
    int tmp2=0;
    cin>>N>>M;
    DP[0]=1;
    DP[1]=1;
    for(int i=2;i<=N;i++){
        DP[i]=DP[i-1]+DP[i-2];
    }

    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        result*=DP[tmp-tmp2-1];
        tmp2=tmp;
    }

    cout<<result*DP[N-tmp2]<<endl;

    return 0;
}
