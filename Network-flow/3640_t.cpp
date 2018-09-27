#include<iostream>
#include <queue>
#include <vector>
using namespace std;

int capacity[1001][1001]={0,};
vector<int>adj[1001];
bool visit[1001];
int mi=0;
void mcmf(int a,int v){
    int dist[1001];
    bool inq[1001]={0};
    queue<int>q;
    for(int i=0;i<1001;i++){
        dist[i]=10000;
    }
    dist[a]=0;
    inq[a]=true;
    visit[0]=true;
    q.push(a);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        inq[curr]=false;
        int n=adj[curr].size();
        for(int i=0;i<n;i++){
            if(visit[adj[curr][i]]==false&&dist[curr]+capacity[curr][adj[curr][i]]<dist[adj[curr][i]]) {
                dist[adj[curr][i]] = dist[curr] + capacity[curr][adj[curr][i]];
                if(inq[adj[curr][i]]==false) {
                    inq[adj[curr][i]] = true;
                    q.push(adj[curr][i]);
                }
            }
        }
    }
    mi+=dist[v];
}

int main(){
    int v,e;
    int result;
    while(cin>>v>>e) {
        for (int i = 0; i < v; i++) {
            visit[i] = false;
        }

        for (int i = 0; i < e; i++) {
            int first, second, cost;
            cin >> first >> second >> cost;
            capacity[first][second] = cost;
            capacity[second][first] = cost * (-1);
            adj[first].push_back(second);
        }
        mcmf(1, v);
        mcmf(1, v);
        for (int i = 0; i < 1001; i++) {
            for (int p = 0; p < 1001; p++) {
                capacity[i][p] = 0;
            }
        }
        cout<<mi<<endl;
    }
    return 0;
}