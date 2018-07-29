#include <iostream>
#include <vector>

using namespace std;

int MAX(int x,int y){
    if(x<y)
        return y;
    else
        return x;
}

int main(){
    vector<int> stair;
    vector<int> DP;

    int N;
    int S;
    cin>>N;
    stair.resize(N+1);
    DP.resize(N+1);
    stair[0]=0;
    for(int i=1;i<=N;i++){
        cin>>S;
        stair[i]=S;
    }
    DP[1]=stair[1];
    DP[2]=stair[1]+stair[2];
    DP[3]=MAX(stair[1],stair[2])+stair[3];
    for(int i=4;i<=N;i++){
        DP[i]=MAX((DP[i-3]+stair[i-1]+stair[i]),(DP[i-2]+stair[i]));
    }
    cout<<DP[N];

    return 0;
}