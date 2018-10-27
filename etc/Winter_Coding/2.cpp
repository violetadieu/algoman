#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    bool visit[12][12]={0,};
    string s="";
    int answer=0;
    pair<int,int>charactor=make_pair(5,5);
    for(int i=0;i<s.length();i++){
        if(s[i]=='U'){
            if(charactor.first==0)
                continue;
            else{
                visit[charactor.first][charactor.second]=true;
                charactor.first--;
            }
        }
        else if(s[i]=='D'){
            if(charactor.first==10)
                continue;
            else{
                visit[charactor.first][charactor.second]=true;
                charactor.first++;

            }
        }
        else if(s[i]=='L'){
            if(charactor.second==0)
                continue;
            else{
                visit[charactor.first][charactor.second]=true;
                charactor.second--;

            }
        }
        else if(s[i]=='R'){
            if(charactor.second==10)
                continue;
            else{
                visit[charactor.first][charactor.second]=true;
                charactor.second++;

            }
        }
    }
    for(int i=1;i<12;i++){
        for(int k=1;k<12;k++){
            if(visit[i][k]==true)
                answer++;
        }
    }
    cout<< answer;
    return 0;
}