#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int it=0;it<skill_trees.size();it++){
        bool flag=true;
        string now=skill_trees[it];
        string sk=skill;
        for(int i=0;i<now.length();i++){
            if(sk.find(now[i])<=sk.length()){
                if(now[i]==sk[0]){
                    sk.erase(sk.begin(),sk.begin()+1);
                }
                else {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            answer++;
    }
    return answer;
}

int main(){
    string skill="CBD";
    vector<string>skill_trees={"BACDE","CBADF","AECB","BDA"};
    cout<<solution(skill,skill_trees);
    return 0;
}
