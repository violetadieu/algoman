#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
vector<int>k;
vector<pair<int,int>>rope;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        rope.push_back(make_pair(a,b));
    }
    sort(rope.begin(),rope.end());

    v.push_back(rope[0].second);
    for(int i=1;i<n;i++){
        if(rope[i].second>v.back())//추가 가능
            v.push_back(rope[i].second);//문제 x
        else{//지워야하는 경우
            auto pos=lower_bound(v.begin(), v.end(), rope[i].second);//바꿔야 하는 위치 출력
            k.push_back(*pos);
            *pos=rope[i].second;
        }
    }
    cout<<n-v.size()<<endl;
    for(int i=0;i<n;i++){
        for(int p=0;p<n;p++){
            if(k[i]==rope[p].second){
                cout<<rope[p].first<<endl;
            }
        }
    }

    return 0;
}