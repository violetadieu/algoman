#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ctoi(char c){
    if (c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}
int main(){
    int capacity[52][52]={0,};
    int visit[52],prev[52];
    queue<int>q;
    int n;
    int result=0;
    cin>>n;
    while(n--){
        char a,b;
        int v;
        cin>>a>>b>>v;
        capacity[ctoi(a)][ctoi(b)]+=v;
        capacity[ctoi(b)][ctoi(a)]+=v;
    }
    while(1){
        memset(visit,0, sizeof(visit));
        memset(prev,-1,sizeof(prev));
        q.push(0);
        visit[0]=1;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            for(int i=0;i<52;i++){
                if(capacity[now][i]>0){
                    if(visit[i]==0){
                        visit[i]=1;
                        prev[i]=now;
                        q.push(i);
                    }
                }
            }
        }//경로 탐색(bfs)
        int now=25;//Z도착시
        if(prev[now]==-1)break;//다못왓으면 펑(경로가 존재하지 않음)

        int m=capacity[prev[now]][now];
        while(prev[now]!=-1){//역방향으로 가면서 최소유량 구하기
            if(m>capacity[prev[now]][now])
                m=capacity[prev[now]][now];//최소유량 구하기
            now=prev[now];//뒤로 되돌아가기
        }
        now=25;
        while(prev[now]!=-1){//역방향으로 가면서 유량 더하기
            capacity[prev[now]][now]-=m;
            capacity[now][prev[now]]+=m;
            now=prev[now];
        }
        result+=m;
    }

    cout<<result;
    return 0;
}