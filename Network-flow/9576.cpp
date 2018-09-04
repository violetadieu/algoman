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
    int c;//case 수
    int n;//학생 수
    int t;//책의 수
    cin>>c;
    for(int k=0;k<c;k++) {
        cin >> t >> n;
        for (int i = 1; i <= n; i++) {
            int max,min;
            cin>>min>>max;
                for(int i=min;i<=max;i++) {
                    job[i].push_back(i);
                }
            for (int j = 1; j <= t; j++) {
                visit[j] = false;
            }
            avail += input(i);
        }
    }
    cout<<avail;
    return 0;
}
