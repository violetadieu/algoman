/*
Tag : 구현


*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    vector<vector<char>>spin[4];
    int ans=0;
    int N;
    cin>>N;
    vector<vector<char>>S(N);
    vector<vector<char>>T(N);
    for(int i=0;i<N;i++){
            string tmp;
            cin>>tmp;
            for(int p=0;p<tmp.length();p++)
                S[i].push_back(tmp[p]);

    }
    for(int i=0;i<4;i++)
        spin[i].resize(N);
    spin[0]=S;
    for(int i=0;i<N;i++){
            string tmp;
            cin>>tmp;
            for(int p=0;p<tmp.length();p++) {
                T[i].push_back(tmp[p]);
                if(S[i][p]!=tmp[p])
                    ans++;
            }
    }
    //회전 페이즈
    //(n,m)->(n,N-m)

    for(int c=1;c<4;c++){
        int cnt=0;
        for(int i=0;i<N;i++){
            for(int k=0;k<N;k++){
                spin[c][i].push_back(spin[c-1][N-(k+1)][i]);
                if(spin[c][i][k]!=T[i][k])
                    cnt++;
            }
        }
        if(c==1||c==3)
            cnt++;
        else
            cnt+=2;

        if(ans>cnt)
            ans=cnt;
    }
    cout<<ans<<endl;
    //비교 페이즈

    return 0;
}
