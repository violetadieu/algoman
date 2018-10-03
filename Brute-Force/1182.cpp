#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>num;
int N,S;
int cnt=0;
int dfs(int ans,int sum,int length){
    if(ans==N){
        if(sum==S&&length!=0) {
            cnt++;
        }
        return 0;
    }
    dfs(ans+1,sum+num[ans],length+1);

    dfs(ans+1,sum,length);
    return 0;
}

int main(){
    cin>>N>>S;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        num.push_back(a);
    }
    dfs(0,0,0);
    cout<<cnt;
    return 0;
}