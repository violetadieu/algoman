#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int>pq(works.begin(),works.end());
    while(n!=0){
        int tmp=pq.top();
        if(tmp>0){
            pq.pop();
            pq.push(tmp-1);
        }
        n--;
    }
    
    while(!pq.empty()){
        answer+=pq.top()*pq.top();
        pq.pop();
    }
    
    return answer;
}
