#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    vector<pair<int,int>>v;
    vector<int>rank;
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    for (int j = 0; j <N; ++j) {
        int k=1;
        for (int i = 0; i <N ; ++i) {
            if(v[j].first<v[i].first&&v[j].second<v[i].second){
                   k++;
            }
        }
        rank.push_back(k);
    }
    for (int l = 0; l <rank.size(); ++l) {
        cout<<rank[l]<<" ";
    }
    return 0;
}