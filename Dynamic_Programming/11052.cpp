#include <iostream>

int m(int x,int y);

int main(){
    int n=0;
    int P[10001]={0,};
    int DP[1001]={0,};
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>P[i];
    }
    DP[1]=P[1];
    for(int i=1;i<=n;i++){
        for(int k=1;k<=i;k++){
            DP[i]=m(DP[i],DP[i-k]+P[k]);
        }
    }
    std::cout<<DP[n];
    return 0;
}

int m(int x,int y){
    if(x<y)
        return y;
    else
        return x;
}