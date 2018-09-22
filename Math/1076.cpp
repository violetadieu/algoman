#include <iostream>
#include <string>

using namespace std;

int main(){
    string s[3];
    int result=0;

    for(int i=0;i<3;i++){
        cin>>s[i];
    }
    if(s[0]=="brown")
        result+=10;
    else if(s[0]=="red")
        result+=20;
    else if(s[0]=="orange")
        result+=30;
    else if(s[0]=="yellow")
        result+=40;
    else if(s[0]=="green")
        result+=50;
    else if(s[0]=="blue")
        result+=60;
    else if(s[0]=="violet")
        result+=70;
    else if(s[0]=="grey")
        result+=80;
    else if(s[0]=="white")
        result+=90;

    if(s[1]=="brown")
        result+=1;
    else if(s[1]=="red")
        result+=2;
    else if(s[1]=="orange")
        result+=3;
    else if(s[1]=="yellow")
        result+=4;
    else if(s[1]=="green")
        result+=5;
    else if(s[1]=="blue")
        result+=6;
    else if(s[1]=="violet")
        result+=7;
    else if(s[1]=="grey")
        result+=8;
    else if(s[1]=="white")
        result+=9;

    if(s[2]=="brown")
        result*=10;
    else if(s[2]=="red")
        result*=100;
    else if(s[2]=="orange")
        result*=1000;
    else if(s[2]=="yellow")
        result*=10000;
    else if(s[2]=="green")
        result*=100000;
    else if(s[2]=="blue")
        result*=1000000;
    else if(s[2]=="violet")
        result*=10000000;
    else if(s[2]=="grey")
        result*=100000000;
    else if(s[2]=="white")
        result*=1000000000;

    cout<<result;
    return 0;
}