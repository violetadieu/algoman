#include <stdio.h>
#include <vector>
using namespace std;

int n,k;
vector<int> adj[505];
int a[505];
int b[505];
int vis[505];
int vcnt;
int dfs(int cur){
    if(vis[cur]==vcnt)return 0;
    vis[cur]=vcnt;
    for(auto nxt: adj[cur]){
        if(!b[nxt]||dfs(b[nxt])){
            a[cur]=nxt;
            b[nxt]=cur;
            return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        vcnt++;
        ans+=dfs(i);
    }
    printf("%d",ans);
}