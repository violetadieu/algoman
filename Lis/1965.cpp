#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,a;
    vector<int>v;
    cin>>n;
    cin>>a;
    v.push_back(a);//맨 처음 값은 무조건 삽입
    for(int i=1;i<n;i++){
        cin>>a;
        if(a>v.back())
            v.push_back(a);
        else{
            auto it=lower_bound(v.begin(),v.end(),a);
            *it=a;
        }
    }
    cout<<v.size();
    return 0;
}