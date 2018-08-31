#include <iostream>
#include <vector>

using namespace std;

int avail=0;//최종 결과
int task[1001]={0,};
vector<int>job[1001];
bool visit[1001];
int input(int p)
{
    int i, w;

    if (visit[p])    return 0;
    visit[p] = true;

    for (i = 0; i < job[p].size(); i++) {
        w = job[p][i];

        if (!task[w] || input(task[w])) {
            task[w] = p;
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;//직원 수
    int t;//일의 수
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        for(int p=1;p<=tmp;p++){
            int num;
            cin>>num;
            job[i].push_back(num);
        }
        for(int j=1;j<=n;j++){
            visit[j]=false;
        }
        avail+=input(i);
    }

    cout<<avail;
    return 0;
}
