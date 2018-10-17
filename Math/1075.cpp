#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n,f;
    cin>>n>>f;
    n/=100;
    n*=100;//맨 뒤의 두자리를 00으로 바꿔주는 과정
    for(int i=0;i<100;i++) {//뒤 두자리를 0~99까지
        int tmp = n + i;
        if (!(tmp % f)) {
            if (i < 10)
                cout << "0" << i;
            else
                cout << i;
            break;
        }
    }
    return 0;
}