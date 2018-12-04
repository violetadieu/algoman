#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int *num=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }

    sort(&num[0],&num[n]);
    cout<<num[k-1];
    delete[] num;

    return 0;

}