#include <iostream>

using namespace std;

int isPrimeNumber(int num){
    if(num==1)
        return 0;
    for(int i=2;i<num;i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}

int main(){
    int N;
    int result=0;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        result+=isPrimeNumber(a);
    }
    cout<<result;

    return 0;
}