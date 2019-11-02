#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}

long long sum(vector<long long> &tree,int node, int start, int end, int left, int right){
    if(start>right||end<left){
        return 0;
    }
    if(left<=start&&end<=right){
        return tree[node];
    }
    return sum(tree,node*2,start,(start+end)/2,left,right)+sum(tree,node*2+1,(start+end)/2+1,end,left,right);
}

void update( vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if(index>end||index<start)
        return;
    tree[node]=tree[node]+diff;
    if(start!=end){
        update(tree,node*2,start,(start+end)/2,index,diff);
        update(tree,node*2+1,(start+end)/2+1,end,index,diff);
    }
}

int main()
{
    int n,m,k;

    cin>>n>>m>>k;
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long>v;
    vector<long long>tree(tree_size);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    init(v, tree, 1, 0, n-1);

    for(int i=0;i<m+k;i++){
        int a,b,c;

        cin>>a>>b>>c;

        if(a==1){
            b--;
            int diff=c-v[b];
            update(tree,1,0,n-1,b,diff);
            v[b]=c;
        }
        else if(a==2){
            cout<<sum(tree,1,0,n-1,b-1,c-1)<<endl;

        }


    }

    return 0;
}

