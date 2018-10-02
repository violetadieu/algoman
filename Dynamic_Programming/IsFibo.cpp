#include <iostream>
#include <vector>

using namespace std;
int DP[10000]={0,};

int main(){
    int n;
    cin>>n;//판단할 수의 개수 지정
    DP[0]=0;
    DP[1]=1;
    for(int i=2;i<=9999;i++){
        DP[i]=DP[i-1]+DP[i-2];//피보나치수열 저장
    }

    for(int i=1;i<=n;i++){
        int k;//판단할 숫자
        cin>>k;
        for(int p=2;DP[p]<=k;p++){
            if(DP[p]==k) {
                cout << "IsFibo" << endl;
                break;
            }
            if(DP[p+1]>k)
                cout<<"IsnotFibo"<<endl;
        }

    }

    return 0;
}