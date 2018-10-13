#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s;
    string tmp_s;
    int sum=0;
    bool flag=true;//괄호의 위치(값을 바꾸면 괄호를 열거나(닫거나)한다)
    cin>>s;
    for(int i=0;i<=s.length();i++){
             if(s[i]=='+'||i==s.length()||s[i]=='-') {//55-50+40-100+10-25
                 int tmp2=stoi(tmp_s);
                 if(flag)
                     sum+=tmp2;
                 else
                     sum-=tmp2;
                 if(s[i]=='-')
                    flag=false;//flip

                 tmp_s = "";
             }
            else{
             tmp_s+=s[i];
            }
    }
    cout<<sum;
    return 0;
}