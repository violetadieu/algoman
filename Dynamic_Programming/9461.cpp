#include <iostream>
#include <vector>

using namespace std;

int main(){
    int P[101]={0,1,1,1,2,2,3,4,5,7,9};
    int N=0;
    vector<int>result;
    cin>>N;
    result.resize(N);
    for(int i=0;i<N;i++){
        cin>>result[i];
    }
    for(int p=11;p<=101;p++){
        P[p]=P[p-1]+P[p-5];
    }
    for(int k=0;k<N;k++){
        cout<<P[result[k]]<<endl;
    }
    return 0;
}