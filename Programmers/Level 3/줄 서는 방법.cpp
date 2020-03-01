#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> solution(int n, long long k) {
    vector<vector<int>>vo;
    vector<int> answer;
    vector<int>v;
    long long tmp=1;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    do{
        if(tmp==k){
            answer=v;
            break;
        }
        tmp++;

    }while(next_permutation(v.begin(),v.end()));


    return answer;
}
