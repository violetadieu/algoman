#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N,Q;
long long tree[111112];
long long v[100002];

long long sum(long long i){
    long long result=0;
    while(i>0){
        result+=tree[i];
        i-=(i&-i);
    }
    return result;
}

void update(long long i,long long diff){
    while(i<=111112){
        tree[i]+=diff;
        i+=(i&-i);
    }
}

long long getSection(long long start, long long end){
    return sum(end)-sum(start-1);
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>N>>Q;
    for(int i=1;i<=N;i++){
        cin>>v[i];
        update(i,v[i]);
    }

    for(int i=1;i<=Q;i++){
        long long x,y,a,b;
        cin>>x>>y>>a>>b;

        if(x>y) {
            swap(x,y);
        }

        cout << getSection(x, y) << endl;
        long long tmp=b-v[a];
        update(a,tmp);
        v[a]=b;
    }

    return 0;
}
