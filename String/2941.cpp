#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<string> vec = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int index = 0;
    string S;
    cin>>S;
    for(int i=0; i<vec.size(); i++){
        index = S.find(vec[i]);
        for(; index != string::npos; index = S.find(vec[i]))
            S.replace(index, vec[i].length(), "@");
    }
    cout<<S.length();
}
