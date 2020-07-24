#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    int ans=0;
    cin>>n;
    vector<int>prime_num;
    vector<bool>net;
    //소수 구하기
    net.resize(n+1);
    for(int i=2;i<=n;i++){
        if(!net[i]) {
            int stand = i*2;
            while (stand <= n) {
                net[stand] = true;
                stand += i;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(!net[i])
            prime_num.push_back(i);
    }

    int first=0;
    int end=0;
    while(1){
        if(first==prime_num.size()&&end==prime_num.size())
            break;
        int res=0;
        for(int i=first;i<=end;i++){
            res+=prime_num[i];
        }
        if(res>n){
            first++;
        }
        else if(res<n){
            if(end==prime_num.size())
                break;
            end++;
        }
        else{
            ans++;
            first++;
            end++;
        }
    }

    cout<<ans<<endl;

    return 0;
}
