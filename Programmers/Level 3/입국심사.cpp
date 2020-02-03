#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    sort(times.begin(),times.end());
    unsigned long long maxi=times[times.size()-1]*n;

    unsigned long long left=times[0];
    unsigned long long mid=0;
    unsigned long long right=maxi;
    while(left<=right){
        mid=(left+right)/2;
        //cout<<"mid : "<<mid<<endl;
        unsigned long long result=0;
        for(int i=0;i<times.size();i++){
            result+=(mid/times[i]);
        }
        //cout<<result<<endl;
        //더 많은 사람을 심사 가능
        if(result>=n){
            right=mid-1;
            answer=mid;
        }
            //시간이 더필요함
        else if(result<n){
            left=mid+1;
        }

    }

    return answer;
}