#include <iostream>

using namespace std;

int vis[1001];
int point[1001][1001];
int N,M;

int dfs(int cur){
    vis[cur]=1;
    for(int i=0;i<N;i++){
        if(vis[i]==0&&point[cur][i]==1){
            dfs(i);
        }
    }
}

int main(){
    int cnt=0;
    cin>>N>>M;

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        point[a][b]=point[b][a]=1;
    }
    for(int i=0;i<N;i++){
        if(vis[i]==0){
            ++cnt;
            dfs(i);
        }
    }

    cout<<cnt-1;
    return 0;
}