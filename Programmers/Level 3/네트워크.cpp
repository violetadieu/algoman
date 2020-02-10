#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int answer = 0;
bool visit[201]={false,};

void dfs(int start,vector<vector<int>> connect,int size){
    for(int i=0;i<size;i++){
        if(!visit[i]&&connect[start][i]==1){
            visit[i]=true;
            dfs(i,connect,size);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0;i<n;i++){
        if(!visit[i]){
            answer++;
            visit[i]=true;
            dfs(i,computers,n);
        }
    }
    
    return answer;
}
