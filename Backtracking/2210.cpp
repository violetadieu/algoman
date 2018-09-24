#include <iostream>
#include <unordered_set>

using namespace std;

int table[5][5]={0,};
unordered_set<int>num;
int MX[]={-1,1,0,0};
int MY[]={0,0,-1,1};
/*
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1*/
void tracking(int i,int p,int cnt,int result){
    if(cnt>5) {
        num.insert(result);
        return;
    }
    else if(cnt==0)
        result+=table[i][p];
    else{
        result=(result*10)+table[i][p];
    }
    for(int q=0;q<5;q++){
        if(i+MX[q]>=0&&i+MX[q]<5&&p+MY[q]>=0&&p+MY[q]<5){
            tracking(i+MX[q],p+MY[q],cnt+1,result);
        }
    }
}

int main(){
    for(int i=0;i<5;i++){
        for(int p=0;p<5;p++){
            cin>>table[i][p];
        }
    }
    for(int i=0;i<5;i++){
        for(int p=0;p<5;p++){
            tracking(i,p,0,0);
        }
    }

    cout<<num.size();
    return 0;
}