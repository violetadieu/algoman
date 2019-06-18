#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int DP[100001]={0,};
        int M;
        DP[0]=1;
        vector<int>v;
        int tmp;
        cin>>tmp;
        for(int i1=0;i1<tmp;i1++){
            int t;
            cin>>t;
            v.push_back(t);
        }
        cin>>M;
        //input phase
        for(int i2=0;i2<tmp;i2++){
            for(int i3=v[0];i3<=M;i3++){
                DP[i3]+=DP[i3-v[i2]];
            }
        }
        cout<<DP[M]<<endl;
    }

    return 0;
}