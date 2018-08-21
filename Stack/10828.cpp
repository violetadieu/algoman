#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int N=0;
    stack<int> s;
    cin>>N;
    for(int i=0;i<N;i++){
        string order;
        int push_value=0;
        cin>>order;
        if(order=="push"){
            cin>>push_value;
            s.push(push_value);
        }
        else if(order=="pop"){
            if(s.size()==0)
                cout<<"-1"<<endl;
            else {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if(order=="size"){
            cout<<s.size()<<endl;
        }
        else if(order=="empty"){
            if(s.empty()){
                cout<<"1"<<endl;
            } else
                cout<<"0"<<endl;
        }
        else if(order=="top"){
            if(s.empty()){
                cout<<"-1"<<endl;
            } else
                cout<<s.top()<<endl;
        }
    }


    return 0;
}