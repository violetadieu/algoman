#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N,M;
    vector<vector<int>>maze;
    vector<vector<int>>cost;
    cin>>N>>M;
    maze.resize(M);
    cost.resize(M);
    for(int i=0;i<M;i++){
        string s;
        cin>>s;
        for(int i2=0;i2<s.length();i2++){
            maze[i].push_back(s[i2]-'0');
            cost[i].push_back(10001);
        }
    }
    cost[0][0]=0;
    int MX[4]={-1,1,0,0};
    int MY[4]={0,0,-1,1};
    queue<pair<int,int>>q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        pair<int,int>now=q.front();
        q.pop();

        int now_cost=cost[now.second][now.first];
        for(int i=0;i<4;i++){
            pair<int,int>MOVE=make_pair(now.first+MY[i],now.second+MX[i]);
            if(0<=MOVE.second&&MOVE.second<M&&0<=MOVE.first&&MOVE.first<N) {
                int tmp_cost = now_cost;
                if (maze[MOVE.second][MOVE.first] == 1) {
                    tmp_cost += 1;
                }

                if (cost[MOVE.second][MOVE.first] > tmp_cost){
                    cost[MOVE.second][MOVE.first] = tmp_cost;
                    q.push(MOVE);
                }
            }
        }
    }
    cout<<cost[M-1][N-1]<<endl;
    return 0;
}
