#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int>a;
    int sum=-100;

    for(int i=0;i<9;i++){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
        sum+=tmp;
    }
    sort(a.begin(),a.end());

    for(int i=0;i<9;i++) {
        for(int j=i+1;j<9;j++){
            if(a[i]+a[j]==sum){
                a[i]-=a[i];
                a[j]-=a[j];
                break;
            }
        }
        if(a[i]==0) break;
    }
    for(int i=0;i<9;i++){
        if(a[i]!=0)
            cout<<a[i]<<endl;
    }

    return 0;
}