//
// Created by 김동현 on 2018. 9. 20..
//
#include<iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    stack<int>s[6];
    int N,P;
    int result=0;
    cin>>N>>P;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;//a==줄번호,b==프렛
        if(s[a].empty()||s[a].top()<b) {
            s[a].push(b);
            result++;
        }
        else{
            while(!s[a].empty()&&s[a].top()>b){
                s[a].pop();
                result++;
            }
            if(s[a].empty()||s[a].top()!=b){
                s[a].push(b);
                result++;
            }
        }
    }
    cout<<result;
    return 0;
}
