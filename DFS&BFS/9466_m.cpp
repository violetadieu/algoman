#include <iostream>
#include <vector>
using namespace std;
bool visit[100001];

int dfs(int first,int now,int next,vector<int>v){
    if(first==now)//도착(순환 완료)or 자기 자신 지목
        return 0;
    if(now==next){//다음 사람이 자기 자신 지목(본인은 혼자)
        return 1;
    }

    if(dfs(first,v[now],v[next],v)){
        return 1;
    }
    return 0;
}

int solve(vector<int>v){
    int cnt=0;
    for(int k=1;k<=v.size();k++)
        visit[k]=true;
    for(int i=1;i<v.size();i++){
        cnt+=dfs(i,v[i],v[v[i]],v);
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int>v;
        v.push_back(0);//index를 1부터 시작하게 하기 위해(혼란 방지)
        int cnt;
        cin>>cnt;
        for(int k=0;k<cnt;k++){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        cout<<solve(v)<<endl;
    }
    return 0;
}