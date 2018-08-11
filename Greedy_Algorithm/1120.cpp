#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string A="";
    string B="";
    cin>>A>>B;
    int min=999999;
    for(int i=0;i<B.size();i++){
        int count=0;

        for(int k=0;k<A.size();k++){
            if(A[k]!=B[k+i])
                count++;
        }
        if(count<min)
            min=count;
    }
    cout<<min;
    return 0;
}
