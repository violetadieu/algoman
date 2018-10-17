#include <iostream>
#include <string>
using namespace std;

int main(){
    string A,B;
    cin>>A>>B;
    //최댓값 구하기
    string tmp1=A;
    string tmp2=B;
    for(int i=0;i<tmp1.length();i++){
        if(tmp1[i]=='5')
            tmp1[i]='6';
    }
    for(int i=0;i<tmp2.length();i++){
        if(tmp2[i]=='5')
            tmp2[i]='6';
    }
    int result_max=0;
    result_max+=stoi(tmp1);
    result_max+=stoi(tmp2);
    //최솟값 구하기
    tmp1=A;
    tmp2=B;
    for(int i=0;i<tmp1.length();i++){
        if(tmp1[i]=='6')
            tmp1[i]='5';
    }
    for(int i=0;i<tmp2.length();i++){
        if(tmp2[i]=='6')
            tmp2[i]='5';
    }
    int result_min=0;
    result_min+=stoi(tmp1);
    result_min+=stoi(tmp2);
    cout<<result_min<<" "<<result_max;
    return 0;
}