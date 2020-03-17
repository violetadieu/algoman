#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> result) {
    int answer = 0;

    int match[101][101];
    fill(&match[0][0], &match[n][n + 1], 10000);
    for(int i=0;i<result.size();i++){
        match[result[i][0]][result[i][1]]=1;//승리
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int p=1;p<=n;p++){
                if(match[i][p]>match[i][k]+match[k][p])
                    match[i][p]=match[i][k]+match[k][p];
            }
        }
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int k=1;k<=n;k++){
            if(i==k)continue;
            if(match[i][k]==10000&&match[k][i]==10000)
                break;
            cnt++;
        }
        if(cnt==(n-1))
            answer++;
    }

    return answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n=8;
    vector<vector<int>>result={{1,2},{2,3},{3,4},{5,6},{6,7},{7,8},{4,5}};

    cout<<solution(n,result);
    return 0;
}
