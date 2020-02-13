#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=1;
    
    bool DP[2501][2501];
    for(int i=0; i<s.length(); i++){
        DP[i][i]=1;
    }
    for(int i=0; i<s.length()-1; i++){
        if(s[i] == s[i+1]){
            DP[i][i+1]=1;
            answer=2;
        }
        else {
            DP[i][i+1]=0;
        }
    }
    
    for(int i=2;i<=s.length();i++){
        for(int j=0;j<=s.length()-i;j++){
            //cout<<s[j]<<" "<<s[i+j-1]<<" "<<DP[j+1][i+j-2]<<endl;
            if(DP[j+1][i+j-2]&&s[j]==s[j+i-1]){
                DP[j][i+j-1]=true;
                if(i>answer){
                    answer=i;
                }
            }
        }
    }
    
    return answer;
}
