#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int len=budgets.size();
    sort(budgets.begin(),budgets.end());
    for(int i=0;i<budgets.size();i++){
        if(budgets[i]>M/len)
            return M/len;
        else{
            M-=budgets[i];
            len--;
        }
    }

    return budgets.back();
}