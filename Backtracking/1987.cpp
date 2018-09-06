#include <iostream>
#include <vector>
#include <string>
using namespace std;
int r,c;
int log[99];
char board[21][21];
int MAX=0;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
void count(int x,int y,int c){
    log[board[x][y]]=1;
    if(c>26)return ;
    if(c>MAX) MAX=c;
    for(int i=0;i<4;i++) {
        int mx = x + dx[i];
        int my=y+dy[i];
        if(board[mx][my]&&!log[board[mx][my]])
            count(mx,my,c+1);
    }
    log[board[x][y]]=0;
}

int main(){
    int cnt=1;
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int p=1;p<=c;p++) {
            cin >> board[i][p];
        }
    }
    count(1,1,cnt);
    cout<<MAX;
    return 0;
}