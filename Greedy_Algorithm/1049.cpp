#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,M,tmp,final_price;
    int six,six_min=9999;
    int one,one_min=9999;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>six>>one;
        if(six<six_min){
            six_min=six;
        }
        if(one<one_min){
            one_min=one;
        }
    }

    if(N<=6){
        if(six_min<(one_min*N))
            final_price=six_min;
        else
            final_price=(one_min*N);
    }
    else{
        if(six_min>=(one_min*6))
            final_price=one_min*N;
        else{
            int t=N/6;
            final_price=six_min*t+one_min*(N%6);
        }

    }
    cout<<final_price;
    return 0;
}
