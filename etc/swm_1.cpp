#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N=0;
    string ans="";
    cin>>N;

    if(N%2==1) {
        N -= 3;
        ans+='7';
    }
    long long tmp=N/2;
    for(int i=0;i<tmp;i++){
        ans+='1';
    }
    
    return 0;
}
