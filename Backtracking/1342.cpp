#include<iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool visit[11];
int letter[11];
unordered_set<string>chk;
string tmp;
string s;

void dfs(int a){
    visit[a]=true;
    if(tmp.length()==s.length()){
        chk.insert(tmp);
        return;
    }
    for(int i=0;i<s.length();i++){
        if(visit[i]!=true&&s[i]!=tmp[tmp.length() - 1, tmp.length()]){
            dfs(i);
            tmp=tmp.substr(0,tmp.length()-1);
        }
    }
}

int main(){
    cin>>s;
    for(int i=0;i<s.length();i++) {
        visit[i]=false;
    }
    for(int i=0;i<s.length();i++){
        tmp="";
        dfs(i);
    }
    cout<<chk.size();
    return 0;
}