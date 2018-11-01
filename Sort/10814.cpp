#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp_age(pair<int,string>a,pair<int,string>b){
    return a.first<b.first;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    vector<pair<int,string>>v;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        string temp;
        cin>>tmp>>temp;
        v.push_back(make_pair(tmp,temp));
    }
    stable_sort(v.begin(),v.end(),cmp_age);
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<'\n';
    }
    return 0;
}