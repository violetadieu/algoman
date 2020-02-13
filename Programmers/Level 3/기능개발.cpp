#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while(progresses.size()!=0){
        int day=1;
        for(int i=0;i<speeds.size();i++){
            progresses[i]+=speeds[i];
        }
        if(progresses[0]>=100){
            int ans=0;
            while(progresses.size()!=0&&progresses[0]>=100){
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                ans++;
            }
            answer.push_back(ans);
        }
        day++;
    }
    
    
    return answer;
}
