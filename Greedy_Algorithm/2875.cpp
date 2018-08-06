#include<iostream>
#include <vector>

using namespace std;

int main(){
    int N,M,K;
    int team=0;
    cin>>N>>M>>K;
    if(N==0||M==0||(N-2)+(M-1)>=K){
        cout<<team;
        return 0;
    }
    do{
            N-=2;
            M-=1;
            team++;
    }while((N-2)+(M-1)>=K&&N-2>=0&&M-1>=0);
    cout<<team;
    return 0;
}