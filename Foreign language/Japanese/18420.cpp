/*
Tag : DFS&BFS

*/

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int tenkey[4][3] = {
    {7,8,9},
    {4,5,6},
    {1,2,3},
    {0,-1,-1}
};
const int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};
const int INF = 1e9;

inline bool isKeyExist(int x,int y){
    return x >= 0 && x < 4 && y >= 0 && y < 3 && tenkey[x][y] != -1;
}

signed main(){
    int m,r;
    cin >> m >> r;
    int dist[100010][4][3] = {};
    for(int i = 0;i < m;i++){
        for(int j = 0;j < 4;j++){
            for(int k = 0;k < 3;k++) dist[i][j][k] = INF;
        }
    }
    queue<tuple<int,int,int>> que;
    que.emplace(0,3,0);
    dist[0][3][0] = 0;
    while(!que.empty()){
        int rem,x,y;
        tie(rem,x,y) = que.front();
        que.pop();
        int newrem = (rem * 10 + tenkey[x][y]) % m;
        if(dist[newrem][x][y] == INF){
            dist[newrem][x][y] = dist[rem][x][y] + 1;
            que.emplace(newrem,x,y);
        }
        for(int j = 0;j < 4;j++){
            int nx = x + dx[j],ny = y + dy[j];
            if(isKeyExist(nx,ny) && dist[rem][nx][ny] == INF){
                dist[rem][nx][ny] = dist[rem][x][y] + 1;
                que.emplace(rem,nx,ny);
            }
        }
    }
    int ans = INF;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 3;j++) ans = min(ans,dist[r][i][j]);
    }
    cout << ans << endl;
}
