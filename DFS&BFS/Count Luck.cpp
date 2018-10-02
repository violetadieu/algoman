#include <iostream>
#include <string>

using namespace std;

int a,b,first_a,first_b,last_a,last_b;
int n,m;
int MX[]={1,-1,0,0};
int MY[]={0,0,-1,1};
bool visit[101][101];

char forest[101][101]={'a',};

bool chk(int a,int b){//갈수있는 방향이 2개 이상인지 체크하는 함수
    int tmp=0;
    for(int i=0;i<4;i++){
        if(visit[a+MX[i]][b+MY[i]]==false&&a+MX[i]<n&&b+MY[i]<m&&(forest[a+MX[i]][b+MY[i]]=='.'||forest[a+MX[i]][b+MY[i]]=='*'))
            tmp++;
    }
    if(tmp>1)
        return true;

    return false;
}

void dfs(int a,int b,int cnt){
    if(visit[a][b]== true)
        return;
    visit[a][b]=true;
    if(a==last_a&&b==last_b) {
        if (cnt == 0) {
            cout << "Impressed" << endl;
            return;
        }
        else {
            cout<<"Oops!"<<endl;
            return;
        }
    }
    if(chk(a,b))
        cnt--;
    for(int i=0;i<4;i++){
        if(a+MX[i]<n&&b+MY[i]<m&&(forest[a+MX[i]][b+MY[i]]=='.'||forest[a+MX[i]][b+MY[i]]=='*'))
            dfs(a+MX[i],b+MY[i],cnt);
    }
    return;
}

int main(){
    int test_case;
    cin>>test_case;

    for(int i=0;i<test_case;i++) {
        cin >> n >> m;
        for (int p = 0; p < n; p++) {
            for (int k = 0; k < m; k++) {
                cin >> forest[p][k];
                visit[p][k] = false;
                if (forest[p][k] == 'M') {
                    first_a = p;
                    first_b = k;
                } else if (forest[p][k] == '*') {
                    last_a = p;
                    last_b = k;
                }
            }
        }
        int count;
        cin >> count;
        dfs(first_a, first_b, count);
    }

    return 0;
}