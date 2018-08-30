#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cow;//소 마릿수
    int size;//축사 크기
    int count=0;//축사에 들여보낼 수 있는 소의 마릿수
    cin>>cow>>size;
    vector<int>cell;//축사(소가 없음==0,소가 있음==1)
    int cell_available[201][201]={0,};
    cell.resize(size+1);//축사 크기 설정
    for(int i=0;i<size+1;i++){
        cell[i]=-1;//초기화
    }
    for(int i=0;i<cow;i++){
        int condition;//i번째 소가 들어가기 원하는 축사의 갯수
        cin>>condition;
        for(int p=0;p<condition;p++){
            int number;//들어가길 원하는 축사의 번호
            cin>>number;
            cell_available[i][p]=number;
        }
    }

    for(int i=0;i<cow;i++){
        for(int p=0;cell_available[i][p]!=0;p++){//들어가기를 원하는 축사의 번호가 유효한 경우(0이 아닌 경우) 일때만
            if(cell[cell_available[i][p]]==-1){//해당 축사가 빈 경우
                count++;//들여보낼 수 있는 소의 마릿수 증가
                cell[cell_available[i][p]]=i;//해당 축사 상태 변경(i번 소)
                break;
            }
            else{//해당 축사가 채워져 있으나 밀어낼수 있으면 밀어내고 거기다가 배정
                int tmp=cell[cell_available[i][p]];//넣으려는 축사에 원래 있던 소의 번호
                int status=0;//해당 자리에 채워놓아도 되는지 여부
                for(int k=0;cell_available[tmp][k]!=0;k++){
                    if(cell[cell_available[tmp][k]]==-1){
                        cell[cell_available[tmp][k]]=tmp;//해당 축사 상태 변경(i번 소 밀어내기)
                        status=1;
                        break;
                    }
                }
                if(status==1) {
                    cell[cell_available[i][p]] = i;//그 자리에 배정(i번 소)
                    count++;
                    break;
                }
            }

        }
    }
    cout<<count;

    return 0;
}