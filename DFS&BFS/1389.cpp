#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int friends[101][101]={0,};
int visit[101]={0,};
int depth[101]={0,};
int result[101]={0,};

int main(){
    int N,M;
    int min=101;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        friends[a][b]=1;
        friends[b][a]=1;

    }
    for(int i=1;i<=N;i++){
        queue<int>q;
        int cnt=0;
        memset(visit,0, sizeof(visit));
        q.push(i);
        visit[i]=1;
        while(!q.empty()){
            cnt++;
            int curr=q.front();
            q.pop();
            for(int p=1;p<=N;p++){
                if(friends[curr][p]==1&&visit[p]==0) {
                    visit[p]=1;
                    q.push(p);
                    depth[p]=depth[curr]+1;
                }
            }
        }
        for(int k=1;k<=N;k++){
            result[i]+=depth[k];
            depth[k]=0;
        }
    }
    min = result[1];
    int min_person = 1;
    for (int i = 2; i <= N; i++)
    {
        if (min > result[i])
        {
            min = result[i];
            min_person = i;
        }
    }
    cout << min_person << endl;
    return 0;
}