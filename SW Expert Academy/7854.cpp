#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<double>original={1,2,5,25,125};
vector<double>v={1,2,5,25,125};

void inputnum(){
    for(int i=1;i<=9;i++){
        for(int i1=0;i1<5;i1++){
            v.push_back(pow(10,i)*v[i1]);
        }
    }
    sort(v.begin(),v.end());
}

int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    inputnum();
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        int result=0;
        int N;
        cin>>N;
        for(int i1=0;i1<v.size();i1++){
            if(v[i1]<=N)
                result++;
            else
                break;
        }
        cout<<"#"<<i<<" "<<result<<"\n";
    }

    return 0;
}