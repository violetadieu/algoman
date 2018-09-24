#include <iostream>

using namespace std;

int main(){

    int E,K,I;
    int round=0;
    cin>>E>>K>>I;
    while(K!=I){
        K=K/2+K%2;
        I=I/2+I%2;
        round++;
    }
    cout<<round;
    return 0;
}