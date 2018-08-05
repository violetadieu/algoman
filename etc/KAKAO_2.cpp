#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int N,K;
    double scatter=99999999999;
    int dolls[501]={0,};
    cin>>N>>K;
    if(K>N)
        return 0;
    for(int i=0;i<N;i++){
        cin>>dolls[i];
    }
    for(int p=K;p<=N;p++){
        for(int j=0;j<N&&p+j<=N;j++){
            double tmp = 0;
            double tmp2 = 0;
            for(int m=j;m<j+p;m++)
                tmp+=dolls[m];
            tmp/=p;
            for(int m=j;m<j+p;m++)
                tmp2 += pow((dolls[m] - tmp), 2);
            tmp2/=p;
            if (scatter > sqrt(tmp2))
                scatter = sqrt(tmp2);
        }
    }
    cout<<scatter;
    return 0;
}