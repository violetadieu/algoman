#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
bool visit[101]={false,};
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(),costs.end());
    int adj[101][101]={0,};

    for(int i=0;i<costs.size();i++){
        adj[costs[i][0]][costs[i][1]]=costs[i][2];
        adj[costs[i][1]][costs[i][0]]=costs[i][2];

    }
    visit[0]=true;
    vector<int>v;
    v.push_back(0);
    while(v.size()!=n){

        int tmp=100000;
        int start=0;
        int target=0;
        for(int i=0;i<v.size();i++){
            for(int k=0;k<n;k++){
                if(!visit[k]&&adj[v[i]][k]!=0&&adj[v[i]][k]<tmp){
                    tmp=adj[v[i]][k];
                    start=v[i];
                    target=k;
                }
            }
        }

        answer+=tmp;
        visit[target]=true;
        v.push_back(target);
    }

    return answer;
}