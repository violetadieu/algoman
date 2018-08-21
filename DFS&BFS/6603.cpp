#include <iostream>
#include <vector>

using namespace std;

int S[13];
int R[13];
int k;
void dfs(int start, int depth) {

    if(depth == 6) {
        for(int i=0; i<6; i++) {
            cout << R[i] << ' ';
        }
        cout <<endl;
        return;
    }

    for(int i=start; i<k; i++) {
        R[depth] = S[i];
        dfs(i+1, depth+1);
    }

}

int main(){
    while(cin>>k&&k) {
        for(int i=0;i<k;i++){
            cin>>S[i];
        }

        dfs(0,0);
    }
    return 0;
}