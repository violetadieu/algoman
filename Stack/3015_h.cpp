#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n;
    int result=0;
    vector<int>vector1;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        vector1.push_back(tmp);
    }
    stack<int>s;
    s.push(vector1[0]);
    for(int i=1;i<n;i++){
        if(s.top()<vector1[i]){
            result+=s.size();
            while(!s.empty()&&s.top()<vector1[i]){
                s.pop();
            }
            s.push(vector1[i]);
        }
        else{
            result+=s.size();
            s.push(vector1[i]);
        }
    }
    cout<<result;
    return 0;
}