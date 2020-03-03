#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
    if(a.first!=b.first)
       return (a.first > b.first); 
    else
        return (a.second < b.second); 
} 
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int,int>>music;
    map <string,int> g;
    for(int i=0;i<genres.size();i++){
        music.push_back(make_pair(plays[i],i));
        g[genres[i]]+=plays[i];
    }
    sort(music.begin(),music.end(),sortinrev);
    vector<pair<int,string>>gen;
    for(auto i=g.begin();i!=g.end();i++){
        gen.push_back(make_pair(i->second,i->first));
    }
    sort(gen.begin(),gen.end(),greater<pair<int,string>>());
    for(int i=0;i<gen.size();i++){
        int siz=0;
        string gen_name=gen[i].second;
        for(int p=0;p<music.size();p++){
            if(genres[music[p].second]==gen_name){
                if(siz!=2){
                    siz++;
                    answer.push_back(music[p].second);
                }
            }
        }
    }
    return answer;
}
