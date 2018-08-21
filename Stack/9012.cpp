#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char>S;

string vps(string s){
    for(int i=0;i<=s.size();i++){
        if(s[i]=='('){
            S.push('(');
        }
        else if(s[i]==')'){
            if(S.top()!='(')
                return "NO";
            else
                S.pop();
        }
    }
    return "YES";
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
     string s;
     cin>>s;
     cout<<vps(s);
    }

    return 0;
}