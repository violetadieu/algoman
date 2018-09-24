#include <iostream>

using namespace std;

int R,C;
int cnt=0;
char pipe[10001][501]={'a',};
int visit[10001][501]={0,};
int MX[]={-1,0,1};
int MY[]={1,1,1};
int dfs(int a,int b){
    visit[a][b]= 1;

    if(b==(C-1)){
        return 1;
    }

    for(int i=0;i<3;i++){
        if(pipe[a+MX[i]][b+MY[i]]=='.'&&!visit[a+MX[i]][b+MY[i]]){
            int tmp=dfs(a+MX[i],b+MY[i]);
            if(tmp)return tmp;
        }
    }
    return 0;
}

int main(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int p=0;p<C;p++){
            cin>>pipe[i][p];
            visit[i][p]=false;
        }
    }

    for(int i=0;i<R;i++){
        cnt+=dfs(i,0);
    }
    cout<<cnt<<endl;
    return 0;
}