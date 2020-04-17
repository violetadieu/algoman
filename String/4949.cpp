#include<iostream>
#include<stack>
#include<string>
 
using namespace std;
 
stack<int> st;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    //char temp[101];
    string S;
 
    while (1) {
        getline(cin, S);
        if (S.length() == 1 && S[0] == '.')
            break;
 
 
        //스택을 초기화한다.
        while (!st.empty())
            st.pop();
 
        //S를 순회하면서 개행문자('[(')를 만나면 스택에 넣어주고, 닫는 부분에서 짝이 맞는지 확인한다.
        //짝이 맞지 않는다면, break;
        bool flag = true;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(')
                st.push(1);
            else if (S[i] == '[')
                st.push(2);
            else if (S[i] == ')') {
                if (!st.empty() && st.top() == 1)
                    st.pop();
                else {
                    flag = false;
                    break;
                }
            }
            else if (S[i] == ']') {
                if (!st.empty() && st.top() == 2)
                    st.pop();
                else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag && st.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    
 
    return 0;
}
