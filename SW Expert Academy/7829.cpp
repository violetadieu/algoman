#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        int result=0;
        int P;
        vector<int>v;
        cin>>P;
        for(int k=0;k<P;k++){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        sort(v.begin(),v.end());
        result=v.front()*v.back();
        cout<<"#"<<i<<" "<<result<<"\n";
    }

    return 0;
}