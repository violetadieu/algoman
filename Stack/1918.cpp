#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s;
    stack<char> st;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(st.top()!='(') {
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        else if(s[i]=='+'){
            st.push(s[i]);
        }
        else if(s[i]=='-'){
            st.push(s[i]);
        }
        else if(s[i]=='*'){
            st.push(s[i]);

        }
        else if(s[i]=='/'){
            st.push(s[i]);
        }
        else{
            cout<<s[i];
        }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return 0;
}