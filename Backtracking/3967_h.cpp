#include <iostream>
#include <vector>
using namespace std;

char star[6][10]={0,};
int chk[31]={0,};
struct a{
    int x,y;
}arr[15];
int tmp=0;
int success;
/*
....x....
.A.I.D.x.
..x...x..
.x.x.x.x.
....x....
 */
void dfs(int a,int b){
    if(a==tmp){//전부 채워지면 각 라인의 합이26인지 체크
        if(star[0][4]+star[1][3]+star[2][2]+star[3][1]-4*'A'+4!=26)return;
        if(star[0][4]+star[1][5]+star[2][6]+star[3][7]-4*'A'+4!=26)return;
        if(star[1][1]+star[1][3]+star[1][5]+star[1][7]-4*'A'+4!=26)return;
        if(star[1][1]+star[2][2]+star[3][3]+star[4][4]-4*'A'+4!=26)return;
        if(star[3][1]+star[3][3]+star[3][5]+star[3][7]-4*'A'+4!=26)return;
        if(star[1][7]+star[2][6]+star[3][5]+star[4][4]-4*'A'+4!=26)return;
        success=1;//전부 26이면 성공
        return;
    }
    for(int i=0;i<12;i++){
        if(chk[i])continue;//이미 사용된 숫자이면 스킵
        chk[i]=1;//해당숫자 사용 표시
        star[arr[b].y][arr[b].x]=i+'A';//숫자를 1부터 대입(사전순서로 하기 위해 1부터 삽입)
        dfs(a+1,b+1);//재귀
        if(success)return;//성공하면 끝
        star[arr[b].y][arr[b].x]='x';//실패했으면 전부 초기화
        chk[i]=0;
    }
}

int main(){
    for(int i=0;i<5;i++){//입력받기
        for(int k=0;k<9;k++){
            cin>>star[i][k];
            if(star[i][k]>='A'&&star[i][k]<='L')//값이 입력받은 곳은
                chk[star[i][k]-'A']=1;//해당 숫자를 체크
            if(star[i][k]=='x'){//미지수인 경우
                arr[tmp].x=k;//해당 좌표를 저장
                arr[tmp].y=i;
                tmp++;
            }
        }
    }
    dfs(0,0);
    for(int i=0;i<5;i++){
        for(int k=0;k<9;k++){
            cout<<star[i][k];
        }
        cout<<endl;
    }
    return 0;
}