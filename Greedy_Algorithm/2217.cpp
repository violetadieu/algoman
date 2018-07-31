#include <iostream>
#include <vector>
using namespace std;

void change(int &x,int &y);

int main(){
    int N;
    vector<int>rope;
    vector<int>weight;
    cin>>N;
    rope.resize(N);
    weight.resize(N);
    cin>>rope[0];
    weight[0]=rope[0]*N;
    for(int i=1;i<N;i++){
        cin>>rope[i];
        if(rope[i]<rope[i-1])
            change(rope[i],rope[i-1]);
        weight[i]=rope[i]*(N-i);
        if(weight[i]<weight[i-1])
            change(weight[i],weight[i-1]);
    }
    cout<<weight[N-1];

    return 0;
}

void change(int &x, int &y){
    int tmp=x;
    x=y;
    y=tmp;

}