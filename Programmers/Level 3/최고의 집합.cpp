#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    int standard=s/n;
    if(standard==0){
        answer.push_back(-1);
        return answer;
    }
    for(int i=0;i<n;i++) {
        answer.push_back(standard);
        s -= standard;
    }

    for(int i=answer.size()-1;i>=0;i--){
        if(s==0)
            break;
        answer[i]++;
        s--;
    }

    return answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n=2;
    int s=1;

    vector<int>ans=solution(n,s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
