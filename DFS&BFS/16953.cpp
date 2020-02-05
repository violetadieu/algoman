#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    long long int a,b;
    cin>>a>>b;
    queue<pair<int,int>>q;
    q.push(make_pair(b,1));
    while(!q.empty()){
        pair<int,int>now=q.front();
        q.pop();
        if(now.first<a)
            continue;
        if(now.first==a){
            cout<<now.second;
            return 0;
        }
        else if(now.first%2==0){
            q.push(make_pair(now.first/2,now.second+1));
        }
        else if(now.first%10==1) {
            q.push(make_pair(now.first / 10, now.second + 1));
        }
    }
    cout<<-1;
    return 0;
}