#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int counting[10001]={0,};
    int n;
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        counting[tmp]++;
    }
    for(int i=1;i<=10000;i++){
        if(counting[i]>0) {
            for (int k = 0; k < counting[i]; k++)
                cout << i << '\n';
        }
    }
    return 0;
}



