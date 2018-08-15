#include <iostream>
#include <queue>

using namespace std;

int n,k,visited[100001]={0,};
queue<int>q;

int bfs(int n,int k){
    q.push(n);
    visited[n]=1;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        if(p==k){
            return visited[p]-1;
        }
        if(p-1&&visited[p-1]==0){
            visited[p-1]=visited[p]+1;
            q.push(p-1);
        }
        if(p+1<100001&&visited[p+1]==0){
            visited[p+1]=visited[p]+1;
            q.push(p+1);
        }
        if(p*2<100001&&visited[p*2]==0){
            visited[p*2]=visited[p]+1;
            q.push(p*2);
        }
    }
}

int main(){
    cin>>n>>k;
    cout<<bfs(n,k);
    return 0;
}