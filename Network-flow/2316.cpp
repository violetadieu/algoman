#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int current[401][401],flo[401][401],parent[401],capacity[401][401]={0,};
bool visit[401];
int N,P;
vector<int>adj[401];
int flow(int x,int y){
    int ret=0;
    while(1){
        memset(parent,-1,sizeof(parent));
        queue<int>q;
        q.push(x);
        while(!q.empty()&&parent[y]==-1){
            int cur=q.front();
            q.pop();
            for(int next=0;next<adj[cur].size();next++){
                if(!visit[next]&&capacity[cur][next]-flo[cur][next]>0&&parent[next]==-1){
                    parent[next]=cur;
                    q.push(next);
                }
            }
        }
        if(parent[y]==-1)break;
        int max=987654321;
        for(int i=x;i!=y;i=parent[i]){
            max=min(max,capacity[parent[i]][i]-flo[parent[i]][i]);
            if(i!=x&&i!=y)visit[i]=true;
        }
        for(int i=x;i!=y;i=parent[i]){
            flo[parent[i]][i]+=max;
            flo[i][parent[i]]-=max;
        }
        ret+=max;
    }
    return ret;
}
int main(){
    cin>>N>>P;
    for(int i=0;i<P;i++){
        int a=0,b=0;
        cin>>a>>b;
        capacity[a][b]=1;
        capacity[b][a]=1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<flow(1,2);
    return 0;
}