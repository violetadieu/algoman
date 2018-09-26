#include<iostream>
#include <math.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<< max(abs(a - b), abs(b - c)) - 1;
    return 0;
}