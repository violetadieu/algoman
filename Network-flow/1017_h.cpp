#include <iostream>
#include <vector>

using namespace std;

vector<int>num;//입력받을 수
vector<int>tmp[51];//입력받은 수가 짝지을 수 있는 수
int check(int a){//소수인지를 판별하는 함수
    if(a==1)
        return 0;
    for(int i=2;i<a;i++){
        if(a%i==0)
            return 0;
    }
    return 1;
}

int main(){
    int n;//숫자 갯수
    cin>>n;
    if(n%2!=0){//n이 홀수이면
        cout<<"-1";
        return 0;//종료
    }
    num.resize(n+1);//1번부터 n번까지
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<=n;i++){//각 숫자마다

        for(int p=1;p<=n;p++){//자기 자신을 제외한 처음부터 끝까지
            if(i!=p&&!(num[i]%2==0&&num[p]%2==0)){//자기 자신 제외,둘중에 하나는 홀수여야
                if(check(num[i]+num[p])){//두개를 더한게 소수이면
                    tmp[i].push_back(num[p]);//값 저장
                }
            }
        }

    }

    for(int i=0;i<tmp[1].size();i++){
        int t=tmp[1][i];//첫번째 수와 짝지을 수 있는 수 t
        for(int p=2;p<=n;p++){//tmp의 두번째부터 끝까지
            if(tmp[p].size()==1){//그 수와만 짝지을 수 있으면(이거 아니면 짝이 안될때)
                if(tmp[p][0]==t)
                    tmp[1][i]=0;//삭제
            }
        }
    }

    //정렬
    for(int i=0;i<tmp[1].size()-1;i++){
        for(int p=1;p<tmp[1].size();p++){
            if(tmp[1][i]>tmp[1][p]) {//앞에꺼가 더 크면
                int k = tmp[1][i];
                tmp[1][i] = tmp[1][p];
                tmp[1][p] = k;
            }
        }
    }

    //출력
    for(int i=1;i<tmp[1].size();i++){
        cout<<tmp[1][i]<<" ";
    }
    return 0;
}