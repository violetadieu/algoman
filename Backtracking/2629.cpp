#include <iostream>

using namespace std;

bool DP[31][300001]={false,};
int orb[31]={0,};
int weigth[3]={1,0,-1};
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>orb[i];
        DP[N][orb[i]]=true;
    }

    for(int i=1;i<=N;i++){
        for(int p=0;p<3;p++){
            for(int k=0;k<30001;k++){
                int tmp=orb[i]*weigth[p]+k;
                DP[i][tmp]+=DP[i-1][k];
            }
        }
    }
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        int a;
        cin>>a;
        if(DP[N][a+15000]){
            cout<<"Y"<<endl;
        }
        else
            cout<<"N"<<endl;
    }

    return 0;
}