#include <iostream>

using namespace std;

int main(){
    int n;
    int cnt=0;
    int arr[]={64,32,16,8,4,2,1};
    cin>>n;
    for(int i=0;i<7;i++){
        if(n>=arr[i]) {
            n -= arr[i];
            cnt++;
        }
        if(n==0)
            break;
    }
    cout<<cnt;
    return 0;
}