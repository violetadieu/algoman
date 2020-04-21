#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int pipe[17][17];
int n;

int BFS(){
    int ans=0;
    //0==가로, 1==세로, 2==대각선
    pair<pair<int,int>,int>start=make_pair(make_pair(0,1),0);
    queue<pair<pair<int,int>,int>>q;
    q.push(start);
    while(!q.empty()){
        pair<pair<int,int>,int>now=q.front();
        q.pop();

        if(now.first.first==n-1&&now.first.second==n-1){//목적지 도착
            ans++;
        }
        //1.현재상태가 가로.
        if(now.second==0){
            //1-1.가로로 이동
            if(now.first.second+1<n&&pipe[now.first.first][now.first.second+1]==0)
                q.push(make_pair(make_pair(now.first.first,now.first.second+1),0));
            //1-2.대각선으로 이동
            if(now.first.second+1<n&&now.first.first+1<n&&pipe[now.first.first+1][now.first.second+1]==0&&pipe[now.first.first+1][now.first.second]==0&&pipe[now.first.first][now.first.second+1]==0)
                q.push(make_pair(make_pair(now.first.first+1,now.first.second+1),2));
        }
        //2.현재상태가 세로
        else if(now.second==1){
            //2-1. 세로로 이동
            if(now.first.first+1<n&&pipe[now.first.first+1][now.first.second]==0)
                q.push(make_pair(make_pair(now.first.first+1,now.first.second),1));
            //2-2. 대각선
            if(now.first.second+1<n&&now.first.first+1<n&&pipe[now.first.first+1][now.first.second+1]==0&&pipe[now.first.first+1][now.first.second]==0&&pipe[now.first.first][now.first.second+1]==0)
                q.push(make_pair(make_pair(now.first.first+1,now.first.second+1),2));
        }
        //3. 현재상태가 대각선
        else if(now.second==2){
            //1-1.가로로 이동
            if(now.first.second+1<n&&pipe[now.first.first][now.first.second+1]==0)
                q.push(make_pair(make_pair(now.first.first,now.first.second+1),0));
            //1-2.세로로 이동
            if(now.first.first+1<n&&pipe[now.first.first+1][now.first.second]==0)
                q.push(make_pair(make_pair(now.first.first+1,now.first.second),1));
            //1-3.대각선으로 이동
            if(now.first.second+1<n&&now.first.first+1<n&&pipe[now.first.first+1][now.first.second+1]==0&&pipe[now.first.first+1][now.first.second]==0&&pipe[now.first.first][now.first.second+1]==0)
                q.push(make_pair(make_pair(now.first.first+1,now.first.second+1),2));
        }

    }

    return ans;
}

int main(){
    for(int i=0;i<17;i++){
        for(int i2=0;i2<17;i2++){
            pipe[i][i2]=1;
        }
    }

    cin>>n;
    for(int i=0;i<n;i++){
        for(int i2=0;i2<n;i2++){
            cin>>pipe[i][i2];
        }
    }
    cout<<BFS()<<endl;

    return 0;
}
