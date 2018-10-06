#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int>v;
    cin>>n;
    v.push_back(-100000);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a>v.back())
            v.push_back(a);
        else{
            auto it=lower_bound(v.begin(),v.end(),a);
            *it=a;
        }
    }
    cout<<v.size()-1;
    return 0;
}