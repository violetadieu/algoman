#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

int main() {
    long long N,M;
    int ans=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int k;
        cin>>k;
        nums.push_back(k);
    }
    int start_index=0;
    int end_index=0;
    long long plus=0;
    while(true){
        if(plus>=M){
            plus-=nums[start_index++];
        }
        else if(end_index==N)
            break;
        else
            plus+=nums[end_index++];
        
        
        if(plus==M)
            ans++;
    }

    cout<<ans<<endl;
    return 0;
}
