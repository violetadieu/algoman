#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int MF[4]={-1,1,0,0};
int MS[4]={0,0,-1,1};
int map[101][101]={0,};
bool visit[101][101]={false,};
bool melt[101][101]={false,};
vector<pair<int,int>>cheese;
queue<pair<int,int>>air_q;


void bfs_air(){
    //외부 공기 분류
    while(!air_q.empty()){
        pair<int,int>now=air_q.front();
        air_q.pop();


        map[now.first][now.second]=-1;

        for(int i=0;i<4;i++){
            int n_f=now.first+MF[i];
            int n_s=now.second+MS[i];

            if(0<=n_f&&n_f<N&&0<=n_s&&n_s<M&&map[n_f][n_s]==0&&!visit[n_f][n_s]){
                air_q.push(make_pair(n_f,n_s));
                visit[n_f][n_s]=true;
            }
        }
    }
}

bool ismelt(pair<int,int>target){
    int cnt=0;
    for(int i=0;i<4;i++){
        int n_f=target.first+MF[i];
        int n_s=target.second+MS[i];
        if(map[n_f][n_s]==-1)
            cnt++;
    }

    if(cnt>=2) {
        map[target.first][target.second]=0;
        return true;
    }
    else
        return false;
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int k=0;k<M;k++){
            cin>>map[i][k];
            if(map[i][k]==1)
                cheese.push_back(make_pair(i,k));
        }
    }
    //초기 공기 설정
    air_q.push(make_pair(0,0));
    bfs_air();

    int ans=0;
    vector<pair<int,int>>chk;
    while(cheese.size()!=chk.size()){
        for(int i=0;i<cheese.size();i++){
            if(!melt[cheese[i].first][cheese[i].second]&&ismelt(cheese[i])) {
                air_q.push(make_pair(cheese[i].first, cheese[i].second));
                melt[cheese[i].first][cheese[i].second]=true;
                chk.push_back(cheese[i]);
            }
        }
        bfs_air();

        ans++;
    }

    cout<<ans<<endl;
    return 0;
}
