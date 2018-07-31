#include <iostream>
#include <vector>
int main(){
    int N=0;
    int result=1;
    std::vector<int>S;
    std::vector<int>E;
    std::cin>>N;
    S.resize(N);
    E.resize(N);
    std::cin>>S[0]>>E[0];
    for(int i=1;i<N;i++) {
        std::cin >> S[i] >> E[i];
        if((E[i]<E[i-1])||(E[i]==E[i-1]&&S[i]<S[i-1])){
            int tmp=E[i];
            E[i]=E[i-1];
            E[i-1]=tmp;
            tmp=S[i];
            S[i]=S[i-1];
            S[i-1]=tmp;
        }
    }
    for(int i=1;i<N;i++) {
        if (S[i] >= E[i - 1]) {
            result++;
        } else{
            S[i]=S[i-1];
            E[i]=E[i-1];
        }
    }
    std::cout<<result;

    return 0;
}