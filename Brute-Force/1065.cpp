#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int N;
    int result=99;
    cin>>N;
    for(int i=100;i<=N;i++){
        int a=i/100;//9
        int b=(i%100)/10;//8
        int c=i%10;//7
        if(abs(a-b)==abs(b-c)&&abs(a-b)==abs(a-c)){
            result++;
        }
    }
    cout<<result;
    return 0;
}