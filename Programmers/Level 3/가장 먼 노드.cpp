#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    sort(edge.begin(),edge.end());
    int answer = 0;
    int far=0;
    int cost[20001];
    bool visit[20001]={false,};
    for(int i=0;i<=n;i++){
        cost[i]=99999;
    }
    bool adj[20001][20001]={false,};
    for(int i=0;i<edge.size();i++){
        adj[edge[i][0]][edge[i][1]]=true;
        adj[edge[i][1]][edge[i][0]]=true;
    }
    queue<pair<int,int>>q;
    for(int i=1;i<=n;i++){
        if(adj[1][i]){
            cost[i]=1;
            q.push(make_pair(1,i));
        }
    }
    
    while(!q.empty()){
        cout<<far<<endl;
        pair<int,int>now=q.front();
        q.pop();
        int f=now.first;
        int s=now.second;
        visit[f]=true;
        for(int k=1;k<=n;k++){
            if(!visit[k]&&adj[s][k]&&cost[k]>cost[s]+1){
                cost[k]=cost[s]+1;
                q.push(make_pair(s,k));
                if(cost[k]>far)
                    far=cost[k];
            }
        }
        
    }
    for(int i=0;i<=n;i++){
        if(cost[i]==far)
            answer++;
    }
    return answer;
}
