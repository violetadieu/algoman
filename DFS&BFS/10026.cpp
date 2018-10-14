#include <iostream>
#include <string>

using namespace std;
string pc[101];
int N;
int MX[]={-1,1,0,0};
int MY[]={0,0,-1,1};
bool visit[101][101];

void reset_visit(){//방문여부 초기화
    for(int i=0;i<N;i++){
        for(int k=0;k<N;k++)
            visit[i][k]=false;
    }
}

bool search_area(int x,int y){//색맹이 아닌 사람
    if(visit[x][y])
        return false;
    visit[x][y]=true;
    char tmp=pc[x][y];
    for(int i=0;i<4;i++){
        if(tmp==pc[x+MX[i]][y+MY[i]]&&visit[x+MX[i]][y+MY[i]]==false&&x+MX[i]>=0&&y+MY[i]>=0){
            search_area(x+MX[i],y+MY[i]);
        }
    }
    return true;
}

void change_color(){//색맹인 사람을 위해 색을 변경
    for(int i=0;i<N;i++){
        for(int k=0;k<N;k++){
            if(pc[i][k]=='R')
                pc[i][k]='G';
        }
    }
}
int main(){
    int cnt_area=0;
    int cnt_redisgreen=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>pc[i];
    }
    reset_visit();
    for(int i=0;i<N;i++){
        for(int k=0;k<N;k++)
            if(!visit[i][k]&&search_area(i,k))
                cnt_area++;
    }
    reset_visit();
    change_color();
    for(int i=0;i<N;i++){
        for(int k=0;k<N;k++)
            if(!visit[i][k]&&search_area(i,k))
                cnt_redisgreen++;
    }
    cout<<cnt_area<<" "<<cnt_redisgreen;
    return 0;
}