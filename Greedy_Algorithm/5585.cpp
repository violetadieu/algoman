#include<iostream>

using namespace std;

int main(){
    int price=0;
    int result=0;
    int exchange=0;
    int coin[6]={500,100,50,10,5,1};
    int GY[6]={0,};
    cin>>price;
    exchange=1000-price;
    for(int i=0;i<6&&exchange!=0;i++){
        GY[i]=exchange/coin[i];
        exchange-=GY[i]*coin[i];
    }
    for(int i=0;i<6;i++)
        result+=GY[i];
    cout<<result;
    return 0;
}