#include <vector>
#include <algorithm>
using namespace std;
 
int answer = 9;
 
void dfs(int N, int number, int count, int currentNumber) {
    if (count >= 9)        return;
    if (currentNumber == number) {
        answer = min(answer, count);
        return;
    }
    int tempNumber = 0;
    for (int i = 0; i + count< 9 ; i++) {
        tempNumber = tempNumber * 10 + N;
        dfs(N, number, count + 1 + i, currentNumber + tempNumber);
        dfs(N, number, count + 1 + i, currentNumber - tempNumber);
        dfs(N, number, count + 1 + i, currentNumber * tempNumber);
        dfs(N, number, count + 1 + i, currentNumber / tempNumber);
    }
}
 
int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if (answer == 9)    return -1;
    return answer;
}
