#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int cost[3000001]={0,};
int target[3000001]={0,};
int main(){
    int k;
    int ans;
    vector<int>v;
    cin>>k;
    for(int i=0;i<=k;i++){
        cost[i]=1000;
    }
    int tmp=1;
    int cnt=1;
    cost[2]=1;
    target[2]=1;
    cost[3]=1;
    target[3]=1;
    while(1){
        int tmp=cost[k];
        for(int i=1;i<=k;i++){
            if(cost[i]==cnt){
                cost[i*2]=min(cost[i]+1,cost[i*2]);
                cost[i*3]=min(cost[i]+1,cost[i*3]);
                cost[i+1]=min(cost[i]+1,cost[i+1]);
                if(cost[i*2]==cost[i]+1){
                    target[i*2]=i;
                }
                if(cost[i*3]==cost[i]+1){
                    target[i*3]=i;
                }
                if(cost[i+1]==cost[i]+1){
                    target[i+1]=i;
                }
            }
        }
        cnt++;
        if(cost[k]!=1000&&cost[k]==tmp)
            break;
    }
    cout<<cost[k]<<endl<<k<<" ";
    while(k!=1){
        cout<<target[k]<<" ";
        k=target[k];
    }
    return 0;
}