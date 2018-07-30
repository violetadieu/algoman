#include <iostream>
#include <vector>

std::vector<int>Coin;
std::vector<int>GY;
int divide(int p,int K,int result);
int main(){
    int N=0;
    int K=0;
    std::cin>>N>>K;
    Coin.resize(N);
    GY.resize(N);
    for(int i=0;i<N;i++) {
        std::cin >> Coin[i];
        if (i > 1 && (Coin[i] % Coin[i - 1] != 0 || Coin[i] < Coin[i - 1])){
            std::cout << "-1";
            return 1;
            }
    }
    GY[0]=K/Coin[0];

    for(int p=1;p<N;p++){
        if(Coin[p]<K) {
            if (K % Coin[p] == 0) {
                GY[p] = K / Coin[p];
            } else {
                int result=0;
                GY[p] = divide(p, K, result);
            }
        }
        else{
            std::cout<<GY[p-1];
            return 0;
        }
    }

    return 0;
}

int divide(int p,int K,int result){
    int tmp=K/Coin[p];
    if(K%Coin[p]!=0){
        result+=tmp;
        K-=(tmp*Coin[p]);
        p--;
        result=divide(p,K,result);
        return result;
    }
    else{
        result+=tmp;
        return result;
    }
}