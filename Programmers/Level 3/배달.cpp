#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer=0;

    int adj[52][52]={0,};
    int cost[52];
    for(int i=0;i<road.size();i++){
        if(adj[road[i][0]][road[i][1]]==0)
            adj[road[i][0]][road[i][1]]=road[i][2];
        else if(adj[road[i][0]][road[i][1]]>road[i][2])
            adj[road[i][0]][road[i][1]]=road[i][2];
        if(adj[road[i][1]][road[i][0]]==0)
            adj[road[i][1]][road[i][0]]=road[i][2];
        else if(adj[road[i][1]][road[i][0]]>road[i][2])
            adj[road[i][1]][road[i][0]]=road[i][2];
    }
    for(int i=2;i<=N;i++){
        cost[i]=9999999;
    }
    cost[1]=0;

    queue<int>q;
    for(int i=0;i<=N;i++){
        if(adj[1][i]!=0) {
            q.push(i);
            cost[i]=adj[1][i];
        }
    }

    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=1;i<=N;i++){
            if(adj[now][i]!=0){
                if(cost[i]>cost[now]+adj[now][i]){
                    cost[i]=cost[now]+adj[now][i];
                    q.push(i);
                }
            }
        }
    }

    for(int i=1;i<=N;i++){
        if(cost[i]<=K)
            answer++;
    }

    return answer;
}

int main() {
    //examples
    //vector<vector<int>> road={{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};,N=5,K=3
    vector<vector<int>> road={{1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}};

    int N=6;
    int K=4;
    cout<< solution(N,road,K)<< endl;

    return 0;
}
