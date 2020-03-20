#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string number;
    string ans="0";
    int k;
    cin>>number>>k;
    queue<string>q;
    q.push(number);
    for(int i=0;i<k;i++){
        int size=q.size();
        set<string>chk;
        for(int k=0;k<size;k++){
            string now=q.front();
            q.pop();
            if(chk.count(now)!=0)continue;
            chk.insert(now);
            for(int p=0;p<now.size()-1;p++){
                for(int t=p+1;t<now.size();t++){
                    if(p!=0||now[t]!='0'){
                        swap(now[p],now[t]);
                        q.push(now);
                        swap(now[p],now[t]);
                    }
                }
            }
        }
    }

    while(!q.empty()){
        ans=max(ans,q.front());
        q.pop();
    }
    if(ans[0]=='0'){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}
