#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {

    int n;
    ll first=0;
    ll second=0;
    ll result=987654321121;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int left=0;
    int right=n-1;
    while(left<right){
        ll sum=v[left]+v[right];

        if(abs(sum)<result){
            first=v[left];
            second=v[right];
            result=abs(sum);

        }
        else if(sum<0){
            left++;
        }
        else {
            right--;
        }
    }

    cout<<first<<" "<<second<<endl;

    return 0;
}
