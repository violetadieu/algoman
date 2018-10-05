#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int>broken;//고장난 버튼


int chk(int a){
    int t=a;
    while(t!=0){
        int tmp=t%10;
        for(int i=0;i<broken.size();i++){
            if(tmp==broken[i])
                return 0;
        }
        t/=10;
    }
    return a;
}

int main(){
    int cnt=1;//버튼 누른 횟수
    int curr;//목표 채널
    int num;
    cin>>curr;
    int mini=abs(curr-100);
    cin>>num;
    for(int i=0;i<num;i++){
        int a;
        cin>>a;
        broken.push_back(a);//고장난 버튼의 목록 삽입
    }
    int t=curr;
    while(t/10){
        int tmp=t%10;
        cnt++;
        t/=10;
    }
    int cnt2=cnt;
    for(int i=curr;i>=0;i--){
        if(chk(i)!=0){
            cnt+=curr-i;
            if(mini<cnt){
                cnt=mini;
            }
            break;
        }
    }

    for(int i=curr;i>=0;i++){
        if(chk(i)!=0){
            cnt2+=abs(curr-i);
            if(mini<cnt2){
                cnt2=mini;
            }
            break;
        }
    }
    if(cnt2<cnt)
        cout<<cnt2;
    else
        cout<<cnt;
    return 0;
}