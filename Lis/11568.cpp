#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int>first;
    vector<int>result;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        first.push_back(a);
    }
    result.push_back(first[0]);
    for(int i=1;i<n;i++){
        if(first[i]>result.back())
            result.push_back(first[i]);
        else {
            auto pos = lower_bound(result.begin(), result.end(), first[i]);
            *pos=first[i];
        }
    }
    cout<<result.size();
    return 0;
}