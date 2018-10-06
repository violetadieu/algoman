#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;//전깃줄 개수
    vector<int>v;//설치 가능한 전깃줄의 개수
    int rope[501]={0,};//연결되는 위치의 번호
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        rope[a]=b;//a번 부분과 b번 부분이 전깃줄로 연결되어 있음
    }
    v.push_back(rope[1]);
    for(int i=2;i<=500;i++){//위에서부터 연결 가능 여부를 확인
        if(v.back()<rope[i])
            v.push_back(rope[i]);
        else{
            auto pos=lower_bound(v.begin(),v.end(),rope[i]);
            *pos=rope[i];
        }
    }
    cout<<n-v.size();
    return 0;
}