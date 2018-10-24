#include<iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int>v;
int status[21][21]={0,};
int minimum=10000;
int number;

void perm(vector<int>arr,int depth,int k,int n){
    if(depth==k){
        int tmp=0;
        int tmp2=0;
        for(int i=0;i<n/2;i++){
            for(int p=i+1;p<n/2;p++){
                tmp+=status[arr[i]][arr[p]];
                tmp+=status[arr[p]][arr[i]];
            }
        }
        for(int i=n/2;i<n;i++){
            for(int p=i+1;p<n;p++){
                tmp2+=status[arr[i]][arr[p]];
                tmp2+=status[arr[p]][arr[i]];
            }
        }
        if(abs(tmp-tmp2)<minimum)
            minimum=abs(tmp-tmp2);
    }
    for (int i = depth; i < n; i++) {
        int temp=arr[i];
        arr[i]=arr[depth];
        arr[depth]=temp;
        perm(arr, depth + 1, n, k);
        temp=arr[i];
        arr[i]=arr[depth];
        arr[depth]=temp;
    }

}

int main(){
    cin>>number;
    for(int i=1;i<=number;i++){
        v.push_back(i);
        for(int k=1;k<=number;k++){
            cin>>status[i][k];
        }
    }
    perm(v,0,number,number);
    cout<<minimum;
    return 0;
}