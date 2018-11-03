#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp_y(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    vector<pair<int,int>>v;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),cmp_y);
    for(int i=0;i<n;i++){
        cout<<v[i].first<<' '<<v[i].second<<'\n';
    }
    return 0;
}