#include <iostream>
#include <vector>
using namespace std;
int a,b,c;

int power(int a,int b){
    if(b==0)
        return 1;
    int tmp=power(a,b/2);
    int result=1LL*tmp*tmp%c;
    if(b%2)
        result=1LL*result*a%c;
    return result;
}

int main(){
    cin>>a>>b>>c;
    cout<<power(a,b);
    return 0;
}