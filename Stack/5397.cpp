#include <iostream>
#include <stack>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++) {
        stack<char> stack_1;//비밀번호의 값을 저장할 스택
        stack<char> stack_tmp;//커서의 위치이동에 따라 pop하는 문자를 임시로 저장할 스택
        string password;
        cin >> password;
        for (int p = 0; p < password.length(); p++) {
            if (password[p] == '<') {
                if (!stack_1.empty() || stack_tmp.size() != 0) {
                    stack_tmp.push(stack_1.top());
                    stack_1.pop();
                }
            } else if (password[p] == '>') {
                if (!stack_tmp.empty() || stack_tmp.size() != 0) {
                    stack_1.push(stack_tmp.top());
                    stack_tmp.pop();
                }
            } else if (password[p] == '-') {
                stack_1.pop();
            } else
                stack_1.push(password[p]);
        }

        stack<char> str;
        while (stack_1.size() != 0 || !stack_1.empty()) {
            str.push(stack_1.top());
            stack_1.pop();
        }

        while (str.size() != 0 || !str.empty()) {
            cout << str.top();
            str.pop();
        }
        cout<<"\n";
    }
    return 0;
}