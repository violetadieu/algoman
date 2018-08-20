#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int M,N,K;
int arr[100][100]={0};
int visited[100][100]={0};

int dfs(int y,int x){

    int cnt=1;

    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];

        if(ny<0 || ny>=M || nx<0 || nx>=N)
            continue;

        if(arr[ny][nx] || visited[ny][nx])
            continue;

        visited[ny][nx]++;
        cnt+=dfs(ny,nx);
    }

    return cnt;
}

int main(){

    cin>>M>>N>>K;

    int x1,y1,x2,y2;
    for(int i=0;i<K;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        for(int x=x1;x<x2;x++)
            for(int y=y1;y<y2;y++)
                arr[y][x]++;

    }

    vector<int> ans;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!arr[i][j] && !visited[i][j]){
                visited[i][j]++;
                ans.push_back(dfs(i,j));
            }
        }
    }

    cout<<ans.size()<<endl;

    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

    return 0;
}