#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

void chk(){
    int N,M;//N:원소 갯수,M:찾으려는 원소의 위치(0:A)
    int position=0;//지금 빠저나간 원소의 순서
    queue<pair<char,int>>q;
    vector<int>v;
    v.resize(0);
    cin>>N>>M;
    for(int k=0;k<N;k++){
        int tmp2;
        cin>>tmp2;
        v.push_back(tmp2);
        pair<char,int>t=make_pair('A'+k,tmp2);
        q.push(t);
    }
    sort(v.begin(),v.end());
    for(int p=0;p<N;p++){
        if(v[v.size()]==q.front().second){//제일 큰수가 큐의 제일 앞에 있는가?
            //그럼 적출
            position++;
            if(q.front().first=='A'+M) {
                cout<<position;
                return;
            }
            q.pop();
            v.pop_back();
        }
        //아니면 맨앞을 뒤로 보내기
        else{
            pair<char,int>tmp=q.front();
            q.pop();//맨앞 적출해다가
            q.push(tmp);//맨뒤에 삽입
        }
    }
}

int main(){
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        chk();
    }

    return 0;
}