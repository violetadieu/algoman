#include <iostream>
#include <vector>
using namespace std;

int main(){
    int GY[51]={0,};
    vector<int>number;
    int N;
    int result=0;
    cin>>N;
    number.resize(N);
    for(int i=0;i<N;i++){
        cin>>number[i];
        if(number[i-1]<0)
            number[i]-=number[i]*2;
    }
    GY[0]=number[0];
    for(int i=0;i<=N;i++){
        GY[i]=GY[i-1]+number[i];
    }
    cout<<GY[N];
    return 0;
}