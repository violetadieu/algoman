#include <iostream>
#include <cmath>
using namespace std;

bool result[1000001]={false};
long long num[1000001]={0};

int main(){
    long long original_min;
    long long original_max;
    cin>>original_min>>original_max;
    long long sq_max=(long long)sqrt(original_max);


    long long cnt=0;
    long long ans=0;
    for(long long i=2;i<=sq_max;i++){
        num[i]=i*i;
        cnt++;
    }
    for(long long i=2;i<(cnt+2);i++){
        long long tmp=original_min;
        if(tmp%num[i]!=0){
            tmp=(original_min/num[i]+1)*num[i];
        }
        for(long long k=tmp;k<=original_max;k+=num[i]){
            long long now=k-original_min;
            if(!result[now]) {
                result[now] = true;
                ans++;
            }
        }
    }

    cout<<original_max-original_min-ans+1;

    return 0;
}