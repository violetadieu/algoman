// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(),rocks.end());
    
    int left=1;
    int right=distance;
    
    while(left<=right){
        int mid=(left+right)/2;
        int prev=0;
        int cnt=0;
        for(int i=0;i<rocks.size();i++){
            if(rocks[i]-prev>=mid){
                prev=rocks[i];
            }
            else{
                cnt++;
            }
        }
        
        if(distance-prev<mid)
            cnt++;
        
        if(cnt<=n){
            if(answer<mid){
                   answer=mid;
            }
            left=mid+1;
        }
        else
            right=mid-1;
        }
    
    return answer;
}
