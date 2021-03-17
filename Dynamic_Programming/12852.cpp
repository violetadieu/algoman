#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    pair<int,int> *DP=new pair<int,int>[1000001]{};
    cin>>N;
    for(int i=N;i>1;i--){
        if(i%3==0){
            if(DP[i/3].first==0||DP[i/3].first>DP[i].first+1){
                DP[i/3].first=DP[i].first+1;
                DP[i/3].second=i;
            }
        }
        if(i%2==0){
            if(DP[i/2].first==0||DP[i/2].first>DP[i].first+1){
                DP[i/2].first=DP[i].first+1;
                DP[i/2].second=i;
            }
        }

        if(DP[i-1].first==0||DP[i-1].first>DP[i].first+1){
            DP[i-1].first=DP[i].first+1;
            DP[i-1].second=i;
        }

    }

    cout<<DP[1].first<<endl;

    int tmp=1;
    vector<int>v;
    v.push_back(1);
    while(tmp<N){
        v.push_back(DP[tmp].second);
        tmp=DP[tmp].second;
    }

    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
