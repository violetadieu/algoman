#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int main(){
    string num=" ";
    int Is3by=0;
    cin>>num;
    sort(num.begin(),num.end(),greater<char>());
    string tmp=num;
    if(num[tmp.length()-1]!='0'){
        cout<<"-1";
        return 0;
    } else
        tmp[tmp.length()-1]= NULL;
    for(int i=0;i<num.length()-1;i++){
        Is3by+=num[i]-'0';
    }

    if(Is3by%3!=0){
        cout<<"-1";
        return 0;
    }

    cout<<num;
    return 0;
}