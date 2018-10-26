#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string num;
    cin>>num;

    sort(num.begin(), num.end(), greater<char>());

    cout << num << endl;

    return 0;
}