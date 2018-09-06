
#include <iostream>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    int i,j;
    for(i=0;i*i<n;++i);
    int ans=0;
    for(j=i;j*j<=m;++j){
        ans+=j*j;
    }
    if(ans)
        cout<<ans<<endl<<i*i;
    else
        cout<<"-1";
}