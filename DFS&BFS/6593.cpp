#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int r,l,h;
int MX[]={-1,1,0,0,0,0};
int MY[]={0,0,-1,1,0,0};
int MZ[]={0,0,0,0,-1,1};
string building[31][31];
bool visit[31][31][31];
bool flag;
int second=0;
void dfs(int x,int y,int z,int time){

    if(visit[z][y][x])
        return ;
    visit[z][y][x]=true;
    if(building[z][y][x]=='E'){
        flag=true;
        second=time;
        return;
    }
    for(int i=0;i<6;i++){
        int n_x=x+MX[i];
        int n_y=y+MY[i];
        int n_z=z+MZ[i];

        if(0<=n_x&&n_x<l&&0<=n_y&&n_y<r&&0<=n_z&&n_z<h&&(building[n_z][n_y][n_x]=='.'||building[n_z][n_y][n_x]=='E')){
            dfs(n_x,n_y,n_z,time+1);
        }

    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);


    while(1) {
        building[31][31] = {0,};
        int x,y,z;
        flag=false;
        cin >> h >> r >> l;
        if(h==0&&r==0&&l==0)
            break;
        for (int i0 = 0; i0 < h; i0++) {
            for (int i1 = 0; i1 < r; i1++) {
                cin >> building[i0][i1];
                for(int i2=0;i2<building[i0][i1].length();i2++){
                    visit[i0][i1][i2]=false;
                    if(building[i0][i1][i2]=='S'){
                        z=i0;x=i1;y=i2;
                    }
                }
            }
        }
        dfs(x,y,z,0);
        if(!flag)
            cout<<"Trapped!"<<endl;
        else
            cout<<"Escaped in "<<second<<" minute(s)."<<endl;
    }
    return 0;

}