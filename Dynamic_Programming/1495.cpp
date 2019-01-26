#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    int N,S,M;
    int DP[101][1001]={0,};
    vector<int>v;
    int result=-1;
    cin>>N>>S>>M;
    v.push_back(0);
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    DP[0][S]=1;
    for(int i=1;i<=N;i++){
        for(int i1=0;i1<=M;i1++){
            if(DP[i-1][i1]){
                if(i1+v[i]<=M)
                    DP[i][i1+v[i]]=1;
                if(i1-v[i]>=0)
                    DP[i][i1-v[i]]=1;

            }
        }
    }
    for(int i=0;i<=M;i++){
        if(DP[N][i]==1&&result<i)
            result=i;
    }

    cout<<result<<endl;

    return 0;
}
