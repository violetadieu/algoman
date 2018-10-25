#include <iostream>
#include <string>
using namespace std;

int revx(string s){
    string tmp;
    for(int i=s.length()-1;i>=0;i--){
        tmp+=s[i];
    }
    return stoi(tmp);
}


int main(){
    string x,y;
    int result=0;
    string temp;
    cin>>x>>y;
    result+=revx(x);
    result+=revx(y);
    temp=to_string(result);
    cout<<revx(temp);
    return 0;
}