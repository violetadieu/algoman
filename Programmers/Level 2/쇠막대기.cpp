#include <string>
#include <vector>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int steel=0;
    for(int i=0;i<arrangement.length();i++){
        char now=arrangement[i];
        if(now=='('){
            if(i+1 < arrangement.length() && arrangement[i+1]==')'){
                answer+=steel;
                i++;
            }
            else{
                steel++;
                answer++;
            }
        }
        else if(now==')'){
                steel--;
        }
    }
    return answer;
}
