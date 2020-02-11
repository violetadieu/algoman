#include <string>
#include <vector>
using namespace std;
int answer = 0;

void DFS(vector<int>numbers,int index,int now,int target){

    if(index==numbers.size()&&now==target){
        answer++;
        return;
    }
    if(index==numbers.size())
        return;

    int p=now+numbers[index];
    int m=now-numbers[index];

    DFS(numbers,index+1,p,target);
    DFS(numbers,index+1,m,target);

    return;
}

int solution(vector<int> numbers, int target) {
    DFS(numbers,1,numbers[0],target);
    DFS(numbers,1,numbers[0]*(-1),target);
    return answer;
}