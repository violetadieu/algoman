#include <bits/stdc++.h>
#include <cstdio>
#include <queue>

using namespace std;


int n,m,v;
int adj[1005][1005];
int vis[1005];

void dfs(int cur)
{
    printf("%d ",cur);
    vis[cur]=1;
    for(int i=1;i<=n;++i){
        if(adj[cur][i] && !vis[i]){
            dfs(i);
        }
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=2;
    while(!q.empty()){
        int cur=q.front();
        printf("%d ",cur);
        q.pop();
        for(int i=1;i<=n;++i){
            if(adj[cur][i] && vis[i]!=2){
                vis[i]=2;
                q.push(i);
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&v);
    for(int i=0;i<m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        adj[x][y]=adj[y][x]=1;
    }
    dfs(v);
    puts("");
    bfs(v);
}