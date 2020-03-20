#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
vector<vector<int>> answer;
void hanoi(int num,int start,int goal,int tmp){
    vector<int>v={start,goal};
    if(num==1){
        cout<<start<<" "<<goal<<endl;
        answer.push_back(v);
        return;
    }
    else{
        hanoi(num-1,start,tmp,goal);
        answer.push_back(v);
        cout<<start<<" "<<goal<<endl;
        hanoi(num-1,tmp,goal,start);
    }
}

vector<vector<int>> solution(int n) {
    hanoi(n,1,3,2);
    return answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n=15;
    vector<vector<int>>result=solution(n);

    return 0;
}
