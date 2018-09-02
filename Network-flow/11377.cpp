#include <iostream>
#include <vector>

using namespace std;

int avail=0;//최종 결과
int avail_1=0;
int task[1001]={0,};
vector<int>job[1001];
bool visit[1001];

int input(int p,int m){
    int k;
    if(visit[p])
        return 0;
    visit[p]=true;

    for(int i=m;i<job[p].size();i++){
        k=job[p][i];
        if(task[k]==0||input(task[k],m+1)){
            task[k]=p;
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;//직원 수
    int t;//일의 수
    int k;//2개 할수잇는 직원
    cin>>n>>t>>k;
    for(int i=1;i<=n;i++) {
        int tmp;
        cin >> tmp;
        for (int p = 1; p <= tmp; p++) {
            int num;
            cin >> num;
            job[i].push_back(num);
        }
        for(int j=1;j<=n;j++)
            visit[j]= false;

        avail+=input(i,0);

    }
    for(int i=1;i<=n&&i<=k;i++){

        for(int j=1;j<=n;j++)
            visit[j]= false;
        avail_1+=input(i,0);
    }
    cout<<avail+avail_1;
    return 0;
}

