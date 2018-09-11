#include <iostream>
#include <vector>

using namespace std;
char map[101][101]={0,};
char sub_map[101][101]={0,};
int N,M,sx,sy,kx,ky;
int MX[]={1,-1,0,0};//오른쪽,왼쪽,위,아래
int MY[]={0,0,-1,1};
vector<pair<int,int>>vp;
void copymap(char map[101][101],char sub_map[101][101]){
    for(int i=0;i<N;i++){
        for(int p=0;p<M;p++){
            sub_map[i][p]=map[i][p];
        }
    }
}

void DFS(char sub_map[101][101],int kx,int ky){
    sub_map[kx][ky]='K';
    for(int i=0;i<4;i++){
        if(sub_map[kx+MX[i]][ky+MY[i]]=='.')
            DFS(sub_map,kx+MX[i],ky+MY[i]);
    }
}

int check_school(int sx,int sy){//학교까지 도달 햇는가?
    if(sub_map[sx+1][sy]=='K'||sub_map[sx-1][sy]=='K'||sub_map[sx][sy-1]=='K'||sub_map[sx][sy+1]=='K'){
        return 1;//도달햇으면 1
    }
    return 0;//도달못했으면 0
}

int main(){
    int Max=4;//아무리 많이 세워도 4개가 끝
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int p=0;p<M;p++) {
            cin >> map[i][p];
            if (map[i][p] == 'H'){
                sx = i;
                sy=p;
            }
            if (map[i][p] == 'K'){
                kx = i;
                ky=p;
            }
            if(map[i][p]=='.')
                vp.push_back(make_pair(i,p));
        }
    }

    //세울 벽이 1개인 경우

    for(int i=0;i<N;i++){
        for(int p=0;p<M;p++){
            copymap(map,sub_map);
            if(sub_map[i][p]=='.') {
                sub_map[i][p] = '#';
            }
            DFS(sub_map,kx,ky);
            if(!check_school(sx,sy)){
                Max=1;
                cout<<Max;
                return 0;
            }
        }
    }
    //세울 벽이 2개인 경우
    for(int i=0; i<vp.size()-2; i++) {
        for (int j = i + 1; j < vp.size() - 1; j++){
            pair<int,int>one=vp[i];//1번째벽
            pair<int,int>two=vp[j];//2번째벽
            copymap(map,sub_map);

            sub_map[one.first][one.second]='#';
            sub_map[two.first][two.second]='#';//벽 세우기

            DFS(sub_map,kx,ky);
            if(!check_school(sx,sy)){
                Max=2;
                cout<<Max;
                return 0;
            }
        }
    }
    //벽 3개 세우기
    for(int i=0; i<vp.size()-2; i++) {
        for (int j = i + 1; j < vp.size() - 1; j++) {
            for (int k = j + 1; k < vp.size(); k++) {
                pair<int, int> one = vp[i];//1번째기둥
                pair<int, int> two = vp[j];//2번째기둥
                pair<int, int> three = vp[k];//3번째기둥
                copymap(map,sub_map);

                sub_map[one.first][one.second]='#';
                sub_map[two.first][two.second]='#';
                sub_map[three.first][three.second]='#';//벽 세우기

                DFS(sub_map,kx,ky);
                if(!check_school(sx,sy)){
                    Max=3;
                    cout<<Max;
                    return 0;
                }

            }
        }
    }
    cout<<Max;//4개로 막기 (k의 상하좌우)

    return 0;
}