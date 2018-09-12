#include <iostream>

using namespace std;
int num=0;
int cnt=0;
void new_number(int n){
    cnt++;
    int one=n%10;//해당 수의 1의 자리
    int two=n/10;//10의 자리
    int new_n;//만든 새로운 수

    new_n=(one*10)+(one+two)%10;
    if(new_n==num) {//사이클 완료
        cout << cnt;
        return ;
    }//종료
    new_number(new_n);
}

int main(){
    cin>>num;
    if(num>99)
        return 0;
    new_number(num);

    return 0;
}