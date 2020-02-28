#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int idx_a=0;
    int idx_b=0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<A.size();i++){
        if(A[idx_a]<B[idx_b]){
            idx_a++;
            idx_b++;
            answer++;
        }
        else{
            idx_b++;
        }
    }   
    return answer;
}
