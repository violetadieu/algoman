#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int>rope;
    vector<int>allow;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        rope.push_back(a);
    }
    allow.push_back(rope[0]);
    for(int i=1;i<n;i++){
        if(allow.back()<rope[i])
            allow.push_back(rope[i]);
        else {
            auto pos = lower_bound(allow.begin(), allow.end(), rope[i]);
            *pos=rope[i];
        }
    }
    cout<<n-allow.size();
    return 0;
}