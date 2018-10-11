#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while(cin>>n){
        vector<int>first;
        vector<int>result;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            first.push_back(tmp);
        }
        result.push_back(first[0]);
        for(int i=1;i<n;i++){
            if(result.back()<first[i])
                result.push_back(first[i]);
            else{
                auto pos=lower_bound(result.begin(),result.end(),first[i]);
                *pos=first[i];
            }
        }
        cout<<result.size()<<endl;
    }
    return 0;
}