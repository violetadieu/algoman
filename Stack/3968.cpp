#include <iostream>
#include <stack>

using namespace std;

int main(){

    int n;
    int count=0;
    cin>>n;
    for(int i=0;i<n;i++){
        string word;
        stack<char>s;
        cin>>word;
        for(int p=0;p<word.size();p++){
            if(s.empty())
                s.push(word[p]);

            else if(word[p]=='A'){
                if(s.top()=='A')
                    s.pop();
                else
                    s.push(word[p]);
            }
            else if(word[p]=='B'){
                if(s.top()=='B')
                    s.pop();
                else
                    s.push(word[p]);
            }
        }
        if(s.size()==0)
            count++;
    }

    cout<<count;

    return 0;
}