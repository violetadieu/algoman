#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int score[100000][2];
int n;

int main(){
    int c;
    cin>>c;
    for(int i=1;i<=c;i++){
        int cnt=1;
        cin>>n;
        for(int p=0;p<n;p++){
            int a,b;
            cin>>a>>b;
            score[a][0]=a;
            score[a][1]=b;
        }
        int tmp=score[1][1];//합격한 사람의 면접점수
        for(int p=1;p<=n;p++){
            if(score[p][1]<tmp) {
                tmp=score[p][1];
                cnt++;
            }
        }
        cout<<cnt<<endl;

    }

    return 0;
}