#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int>cost;
    vector<int>original;
    bool adj[501][501]={false,};
    bool visit[501]={false};
    int build[501]={0,};
    cost.push_back(0);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        int t;
        cin>>t;
        cost.push_back(t);
        while(1){
            int tmp;
            cin>>tmp;
            if(tmp==-1)
                break;
            adj[tmp][i]=true;
            build[i]++;
        }
    }
    original=cost;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=1;i<=N;i++){
        if(build[i]==0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int now=pq.top();
        pq.pop();
        visit[now]=true;
        for(int i=1;i<=N;i++){
            if(adj[now][i]){
                if(cost[now]+original[i]>cost[i])
                    cost[i]=cost[now]+original[i];
                adj[now][i]=false;
                build[i]--;
            }
        }
        for(int i=1;i<=N;i++){
            if(build[i]==0&&!visit[i]){
                pq.push(i);
                visit[i]=true;
            }
        }
    }

    for(int i=1;i<=N;i++){
        cout<<cost[i]<<endl;
    }
    return 0;
}