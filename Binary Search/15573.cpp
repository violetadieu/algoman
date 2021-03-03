#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int mine[1003][1003]={0,};
int tmp[1003][1003]={0,};

int N,M,K;
int new_n[]={-1,1,0,0};
int new_m[]={0,0,-1,1};

bool isadjair(int i,int k){
    if(tmp[i-1][k]==0||tmp[i][k-1]==0||tmp[i][k+1]==0||(tmp[i+1][k]==0&&i+1<=K))
        return true;
    else
        return false;
}


int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int strenth=0,ans=987654321;
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        for(int k=1;k<=M;k++){
            cin>>mine[i][k];
            if(strenth<mine[i][k])
                strenth=mine[i][k];
        }
    }
    for(int i=1;i<=M;i++){
        mine[N+1][i]=987654321;
    }


    int left=0;
    int right=strenth;
    while(left<=right){
        int cnt=0;
        int D=(left+right)/2;
        queue<pair<int,int>>q;
        bool chk[1003][1003]={false,};
        for(int i=1;i<=N+1;i++) {
            for (int k = 1; k <= M; k++) {
                tmp[i][k]=mine[i][k];
            }
        }

        for(int i=1;i<=N+1;i++){
            for(int k=1;k<=M;k++){
                if(tmp[i][k]<=D&&isadjair(i,k)) {
                    q.push(make_pair(i,k));
                    chk[i][k]=true;
                }
            }
        }

        while(!q.empty()){
            pair<int,int>now=q.front();
            q.pop();
            tmp[now.first][now.second]=0;
            for(int i=0;i<4;i++){
                int n=now.first+new_n[i];
                int m=now.second+new_m[i];

                if((0<n&&0<m&&n<=N&&m<=M)&&tmp[n][m]<=D&&isadjair(n,m)&&!chk[n][m]) {
                    q.push(make_pair(n,m));
                    chk[n][m]=true;
                }
            }

        }

        for(int i=1;i<=N;i++){
            for(int k=1;k<=M;k++){
                if(chk[i][k]) {
                    cnt++;
                }
            }
        }

        if(cnt>=K){
            if(ans>D)
                ans=D;
            right=D-1;
        }
        else if(cnt<K){
            left=D+1;
        }

    }

    cout<<ans<<endl;

    return 0;
}
