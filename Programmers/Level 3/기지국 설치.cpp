#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start=0;
    vector<pair<int,int>>stoe;
    stoe.push_back(make_pair(0,0));
    for(int i=0;i<stations.size();i++){
        pair<int,int>tower=make_pair(stations[i]-w,stations[i]+w);
        stoe.push_back(tower);
        //cout<<tower.first<<" "<<tower.second<<endl;
    }
    stoe.push_back(make_pair(n+1,n+1));
    //cout<<"possible"<<endl;
    vector<pair<int,int>>range;
    for(int i=1;i<stoe.size();i++){
        int start=stoe[i-1].second+1;
        int end=stoe[i].first-1;
        if(end>=start){
            range.push_back(make_pair(start,end));
        }
    }

    for(int i=0;i<range.size();i++){
        int start=range[i].first;
        int end=range[i].second;
        int now=start;
        while(now<=end){
            answer++;
            now+=2*w+1;
        }
    }
    return answer;
}