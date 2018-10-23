#include<iostream>
#include <vector>
using namespace std;

int main(){
    double n,i;
    double sum=0;
    cin>>n;
    for(i=1;sum<n;i++){
        sum+=i;
    }
    cout<<i-2;
    return 0;
}