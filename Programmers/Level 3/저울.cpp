#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a,string b){
    return a.length()<b.length();
}

int solution(vector<int>weight){
    int answer=0;

    sort(weight.begin(),weight.end());
    answer=weight[0];
    for(int i=1;i<weight.size();i++){
        if(answer+1<weight[i])
            break;
        answer+=weight[i];
    }

    return answer+1;
}
