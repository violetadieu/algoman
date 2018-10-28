#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>v;
int n,finding;

bool searching(int x){
    int left=0;
    int right=v.size();
    while(left<=right){
        int mid=v[(left+right)/2];//처음 중간값 설정

        if(mid==x)
            return true;

        if(x>mid){
            left=(left+right)/2+1;
        }
        else if(x<mid){
            right=(left+right)/2-1;
        }
    }
    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    cin>>finding;
    for(int i=0;i<finding;i++){
        int f;
        cin>>f;
        cout<<searching(f)<<'\n';
    }
    return 0;
}



