#include <iostream>

using namespace std;

int cabage[51][51]={0,};
int visit[51][51]={0,};
int bfs(int i,int v){
    visit[i][v]=1;
    if(cabage[i+1][v]==1&&visit[i+1][v]==0){
        bfs(i+1,v);
    }
    else if(cabage[i-1][v]==1&&visit[i-1][v]==0){
        bfs(i-1,v);
    }
    else if(cabage[i][v+1]==1&&visit[i][v+1]==0){
        bfs(i,v+1);
    }
    else if(cabage[i][v-1]==1&&visit[i][v-1]==0){
        bfs(i,v-1);
    }
}

int main() {
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int M,N,K;
        int count=0;
        cin>>M>>N>>K;
        for(int p=1;p<=K;p++){
            int a,b;
            cin>>a>>b;
            cabage[a][b]=1;
        }

        for(int c=0;c<M;c++){
            for(int d=0;d<N;d++){
                if(cabage[c][d]==1&&visit[c][d]==0){
                    count++;
                    bfs(c,d);
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}