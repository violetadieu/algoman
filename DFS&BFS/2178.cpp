#include <iostream>
#include <queue>

using namespace std;

int count[101][101]{1,};
string maze[101][1]={0,};

void DFS(int x,int y,int k){
    int n=count[x][y];
    count[x][y]+=n;
    if(maze[x+1][0][y]=='1'){//아래로 이동
        DFS(x+1,y,n);
    }
    else if(maze[x][0][y+1]=='1'){//왼쪽으로 이동
        DFS(x,y+1,n);
    }
    else if(maze[x-1][0][y]=='1'){//위로 이동
        DFS(x-1,y,n);
    }
    else if(maze[x][0][y-1]=='1'){
        DFS(x,y-1,n);
    }
}

int main(){
    int N,M;
    char start=maze[0][0][0];
    cin>>N,M;
    for(int i=0;i<4;i++){
        cin>>maze[i][0];
    }
    DFS(0,0,0);
    cout<<count[N][M];
    return 0;
}