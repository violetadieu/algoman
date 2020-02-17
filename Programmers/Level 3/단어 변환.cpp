#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer=100;
bool visit[51]={false,};
//한 글자만 다른지 체크
bool chkword(string a,string b){
    int cnt=0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i])
            cnt++;
        if(cnt>1)
            return false;
    }
    return true;
}
//DFS
void DFS(string begin,string target,int cnt,vector<string>words){
    if(begin==target){
        if(cnt<answer)
            answer=cnt;
        return;
    }
    for(int i=0;i<words.size();i++){
        if(visit[i]!=true&&chkword(begin,words[i])){
            visit[i]=true;
            DFS(words[i],target,cnt+1,words);
            visit[i]=false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    //target 존재 유무
    auto it=find(words.begin(),words.end(),target);
    if(it==words.end())
        return 0;
    DFS(begin,target,0,words);
    return answer;
}