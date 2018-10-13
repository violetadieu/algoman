#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int N;
    vector<int>num_lis;//추의 무게 배열
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        num_lis.push_back(tmp);
    }
    sort(num_lis.begin(),num_lis.end());
    if(num_lis[0]!=1){
        cout<<"1";
        return 0;
    }
    int sum=num_lis[0];
    for(int i=1;i<num_lis.size();i++){
        if(num_lis[i]>sum+1)
            break;

        sum+=num_lis[i];
    }
    cout<<sum+1;

    return 0;
}