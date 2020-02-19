#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
using namespace std;


int main() {
    int n,m;
    int student[32001]={0,};
    vector<int>ans;
    vector<int>adj[32001];
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        student[b]++;
        adj[a].push_back(b);
    }
    queue<int>q;//큐에 맨 뒤 학생 삽입
    for(int i=1;i<=n;i++){
        if(student[i]==0){
            q.push(i);
        }
    }

    for(int i=1;i<=n;i++){
        if(q.empty()){
            return 0;
        }
        int now=q.front();
        q.pop();
        ans.push_back(now);
        for(int k=0;k<adj[now].size();k++){
            student[adj[now][k]]--;
            if(student[adj[now][k]]==0)
                q.push(adj[now][k]);
        }

    }
    for(int i=0;i<ans.size();i++){
        cout<< ans[i]<<" ";
    }
    return 0;
}
