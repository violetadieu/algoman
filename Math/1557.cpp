#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

vector<long long>v;//소수의 제곱수
void PrimeNumber() {
    int arr[42001];
    arr[1] = 1;
    for (int i = 2; i < 42000; i++) {
        if (arr[i] == 0) { // 이미 소수가 아니라고 판별이 난 수는 if문 안에 들어오지 못함
            for (int a = i * i; a < 42000; a += i) { // i를 제외한 i의 배수는 소수가 아님
                arr[a] = 1;
            }
        }
    }
    for(int i=2;i<42000;i++){
        if(!arr[i]){
            v.push_back(i*i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    PrimeNumber();

    long long k;
    cin>>k;

    long long min=k*1;
    long long max=k*2;
    long long  mid;
    while(min<=max){
        long long sum=0;//k까지의 제곱 ㅇㅇ 수
        mid=(min+max)/2;//k는 정답보다 무조건 작기 때문에, 정답과 k사이의 배율을 구해야 함(이분탐색 이용)

        for(int i=0;v[i]<=mid;i++){//k까지의 제곱 ㅇㅇ 수를 구해 빼기
            sum+=mid/v[i];//v[i]로 나눠서 떨어지는 거의 갯수 구하기, 이하의 추가 for문은 중복을 제거와 최종 값을 더하기 위한 것
            for(int i2=0;i2<i&&v[i]*v[i2]<=mid;i2++){//k가 두가지 수의 최소공배
                sum-=mid/(v[i]*v[i2]);
                for(int i3=0;i3<i2&&v[i]*v[i2]*v[i3]<=mid;i3++){
                    sum+=mid/(v[i]*v[i2]*v[i3]);
                    for(int i4=0;i4<i3&&v[i]*v[i2]*v[i3]*v[i4]<=mid;i4++){
                        sum-=mid/(v[i]*v[i2]*v[i3]*v[i4]);
                        for(int i5=0;i5<i4&&v[i]*v[i2]*v[i3]*v[i4]*v[i5]<=mid;i5++){
                            sum+=mid/(v[i]*v[i2]*v[i3]*v[i4]*v[i5]);
                            for(int i6=0;i6<i5&&v[i]*v[i2]*v[i3]*v[i4]*v[i5]*v[i6]<=mid;i6++){
                                sum-=mid/(v[i]*v[i2]*v[i3]*v[i4]*v[i5]*v[i6]);
                            }
                        }
                    }
                }
            }
        }
        if(mid-sum==k)
            break;
        else if(mid-sum<k){
            min=mid+1;
        }
        else if(mid-sum>k){
            max=mid-1;
        }
    }

    for(int i=0;v[i]<=mid;i++){
        if(mid%v[i]==0){
            mid--;
            i=-1;
            continue;
        }
    }

    cout<<mid<<endl;
    return 0;
}
