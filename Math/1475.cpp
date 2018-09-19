#include <iostream>
#include <string>
using namespace std;

int num[10]={1,1,1,1,1,1,1,1,1,1};

int main(){
    string N;
    int result=1;
    cin>>N;
    for(int i=0;i<N.length();i++){
        if(N[i]-'0'==6&&num[N[i]-'0']==0&&num[9]>0){
            num[9]--;
        }

        else if(N[i]-'0'==9&&num[N[i]-'0']==0&&num[6]>0){
            num[6]--;
        }

        else if(num[N[i]-'0']==0){
            result++;
            for(int p=0;p<10;p++)
                num[p]++;
            num[N[i]-'0']--;
        }
        else
            num[N[i]-'0']--;
    }
    cout<<result;
    return 0;
}