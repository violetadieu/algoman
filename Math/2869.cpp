#include <iostream>

using namespace std;

int main(){
    int a,b,v;
    cin.tie(NULL);
    cin>>a>>b>>v;
    cout<<(v-b-1)/(a-b)+1;
    return 0;
}