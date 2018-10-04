#include <iostream>
using namespace std;

int chk(int k){
    int sum=k;
    while(k!=0){
        sum+=k%10;
        k/=10;
    }
    return sum;
}

int main(){
    int N;
    cin>>N;

    for(int i=1;i<=1000000;i++){//ex.N==216
        if(chk(i)==N){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"0"<<endl;
    return 0;
}