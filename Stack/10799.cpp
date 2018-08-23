#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string iron;
    stack<char>s;
    int count=0;
    int iron_cnt=0;
    cin>>iron;
    for(int i=0;i<iron.size();i++){
        if(iron[i]=='('){//철근 혹은 레이저
            s.push('(');//철근 하나 푸쉬
            iron_cnt++;//철근 갯수 추가
            count++;//철근 조각 갯수 추가
        }
        else{
            if(iron[i-1]=='('){//레이저인 경우
                iron_cnt--;//레이저이니 철근 갯수 마이너스
                count--;
                s.pop();//철근인줄 알았던 ( 팝
                count+=iron_cnt;// 철근의 갯수만큼 조각이 늘어남
            }
            else{//철근이 끝나는 곳인 경우
                iron_cnt--;//철근갯수 감소
            }
        }
    }

    cout<<count;

    return 0;
}