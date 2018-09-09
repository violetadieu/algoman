#include <iostream>
#include <vector>

using namespace std;
int N,M,Max=0;
int lab[9][9]={0,};
int sub_lab[9][9]={0,};
int mx[]={-1,0,1,0};
int my[]={0,1,0,-1};
vector<pair<int,int>>vp;

void virus_DFS(int x,int y){
    for(int i=0;i<4;i++){
        int MX=x+mx[i];
        int MY=y+my[i];
        if(MX>=0&&MX<N&&MY>=0&&MY<M){
            if(sub_lab[MX][MY]==0){
                sub_lab[MX][MY]=2;
                virus_DFS(MX,MY);
            }
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){//입력
        for(int p=0;p<M;p++){
            cin>>lab[i][p];
            if(!lab[i][p])vp.push_back(make_pair(i,p));
        }
    }

    //기둥 3개 세우기
    for(int i=0; i<vp.size()-2; i++) {
        for (int j = i + 1; j < vp.size() - 1; j++) {
            for (int k = j + 1; k < vp.size(); k++) {
                pair<int,int>one=vp[i];//1번째기둥
                pair<int,int>two=vp[j];//2번째기둥
                pair<int,int>three=vp[k];//3번째기둥

                for(int n=0;n<N;n++){//기둥을 세울 임시 지도
                    for(int m=0;m<M;m++){
                        sub_lab[n][m]=lab[n][m];
                    }
                }

                sub_lab[one.first][one.second]=1;
                sub_lab[two.first][two.second]=1;
                sub_lab[three.first][three.second]=1;//기둥 세우기

                for(int n=0;n<N;n++){//바이러스 전이
                    for(int m=0;m<M;m++){
                        if(sub_lab[n][m]==2)
                            virus_DFS(n,m);
                    }
                }
                int cnt=0;
                for(int n=0;n<N;n++){//안전구역 갯수 세기
                    for(int m=0;m<M;m++){
                        if(sub_lab[n][m]==0)
                            cnt++;
                    }
                }
                if(Max<cnt)
                    Max=cnt;
            }
        }
    }

    cout<<Max;

    return 0;
}