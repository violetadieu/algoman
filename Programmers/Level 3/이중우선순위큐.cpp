#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int cnt_delete=0;
    int cnt_input=0;
    priority_queue<int,vector<int>>maximum_queue;
    priority_queue<int,vector<int>,greater<int>>minimum_queue;화

    for(int i=0;i<operations.size();i++){
        //도중에 초기화
        if(cnt_delete==cnt_input) {
            priority_queue<int, vector<int>> maxi;
            priority_queue<int, vector<int>, greater<int>> mini;
            maximum_queue = maxi;
            minimum_queue = mini;
        }

        string now=operations[i];
        int value=stoi(now.substr(2,now.size()));
        //문자열 나누기
        //입력의 경우
        if(now[0]=='I'){
            maximum_queue.push(value);
            minimum_queue.push(value);
            cnt_input++;
        }
        //제거의 경우
        else if(now[0]=='D'){
            if(maximum_queue.empty()||minimum_queue.empty())
                continue;
            //최댓값 제거
            cnt_delete++;
            if(value==1){
                maximum_queue.pop();
            }
            //최솟값 제거
            else{
                minimum_queue.pop();
            }
        }
    }
    if(cnt_delete>=cnt_input){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(maximum_queue.top());
        answer.push_back(minimum_queue.top());
    }

    return answer;
}

int main() {
    //test
    vector<string>operations={"I 16","D 1"};
    vector<string>operations2={"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6"};
    solution(operations2);

    return 0;
}
