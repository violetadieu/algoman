#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    vector<pair<int,int>>ans;
    stack<pair<int,int>>s;
    for(int i=0;i<heights.size();i++){
        s.push(make_pair(i,heights[i]));
    }
    stack<pair<int,int>>now;
    now.push(s.top());
    s.pop();
    while(!s.empty()){
        if(!s.empty()&&!now.empty()&&s.top().second>now.top().second){
            ans.push_back(s.top());
            now.pop();
        }
        else{
            now.push(s.top());
            s.pop();
        }
    }
    while(!now.empty()){
        ans.push_back(now.top());
        now.pop();
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<heights.size();i++){
        if(ans[i].second==heights[i])
            answer.push_back(0);
        else{
            answer.push_back(ans[i].first+1);
        }
    }

    return answer;
}