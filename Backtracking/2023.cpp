//
// Created by 김동현 on 2018. 9. 20..
//
#include<iostream>
#include <string>
#include <math.h>

using namespace std;
int N;
int m=1;

bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

void tracking(int n){
    for(int i=1;i<=9;i++){
        if(n>(m/10)&&n<m&&isPrime(n)){
            cout<<n<<endl;
            return ;
        }
        if(isPrime(n)&&n<m){
            int k=n*10+i;
            tracking(k);
        }
        else
            return;

    }
}

int main(){

    cin>>N;
    for(int i=0;i<N;i++){
        m*=10;
    }
    tracking(2);
    tracking(3);
    tracking(5);
    tracking(7);

    return 0;
}