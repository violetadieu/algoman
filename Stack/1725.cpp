#include <iostream>
#include<stack>
#include <vector>
using namespace std;

int main(){
    int count=0;
        cin >> count;
        vector<int>height;
        vector<int>counting={0,};
        stack<int>s;
        int c=0;
        int max_area=count;//높이에 상관없이 가장 작은 넓이=너비*1
        height.resize(count);
        counting.resize(c);
        for(int i=0;i<count;i++){
            cin>>height[i];
        }
        for(int i=0;i<count;i++){
            if(s.empty()){
                c++;
                s.push(height[i]);
                counting.resize(c);
                counting[0]++;
            }
            else{
                if(height[i]<height[i-1]||i==count){
                    for(int p=counting.size()-1;p>-1;p--){
                        if(max_area<s.top()*counting[p]){
                            max_area=s.top()*counting[p];
                            s.pop();
                        }
                        else
                            s.pop();
                    }
                    while( !s.empty() ) s.pop();
                    c--;
                    counting.resize(0);
                } else{
                    if(s.top()!=height[i]) {
                        s.push(height[i]);
                        c++;
                        counting.resize(c);
                    }
                    for(int p=0;p<counting.size();p++){
                        counting[p]++;
                    }
                }
            }
        }
        for(int p=counting.size()-1;p>-1&&s.size()!=0;p--){
            if(max_area<s.top()*counting[p]){
                max_area=s.top()*counting[p];
                s.pop();
            }
            else
                s.pop();
        }
        cout<<max_area;

    return 0;
}