#include <iostream>
#include <math.h>
using namespace std;

int result=0;
int n,r,c;

void recursion(int x,int y,int len){
    if(x==r && y==c){
        cout<<result<<endl;
        exit(0);
    }
    if(len==1){
        result++;return;
    }
    if(!(x<=r && r<x+len && y<=c && c<y+len)){
        result += len*len;
        return;
    }
    recursion(x,y,len/2);
    recursion(x,y+len/2,len/2);
    recursion(x+len/2,y,len/2);
    recursion(x+len/2,y+len/2,len/2);

}

int main(){
    cin>>n>>r>>c;
    recursion(0,0,pow(2,n));
    return 0;
}