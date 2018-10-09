#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        stack<char>stack1;
        cin>>s;
        for(int k=0;k<=s.length();k++){
            if(k==s.length()){
                cout<<"YES"<<endl;
                break;
            }
            if(s[k]=='('||s[k]=='{'||s[k]=='[')
                stack1.push(s[k]);
            else if(!stack1.empty()&&s[k]==')'&&stack1.top()=='(')
                stack1.pop();
            else if(!stack1.empty()&&s[k]==']'&&stack1.top()=='[')
                stack1.pop();
            else if(!stack1.empty()&&s[k]=='}'&&stack1.top()=='{')
                stack1.pop();
            else {
                cout << "NO" << endl;
                break;
            }
        }
    }
    return 0;
}