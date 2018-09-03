#include <iostream>
#include <vector>

using namespace std;
bool visit[101];
vector<int>people[101];
int notebook[5001]={0,};
int result=0;
int input(int p){
    int k;
    if(visit[p])
        return 0;
    visit[p]=true;

    for(int i=0;i<people[p].size();i++){
        k=people[p][i];
        if(notebook[k]==0||input(notebook[k])){
            notebook[k]=p;
            return 1;
        }
    }
    return 0;
}

int main(){
    int human;
    int num;
    cin>>human>>num;
    int tmp;
    while(cin>>tmp&&tmp<=human){
        int numberofnotebook;
        cin>>numberofnotebook;
        people[tmp].push_back(numberofnotebook);
    }

    for(int i=1;i<=human;i++){
        for(int i=1;i<=human;i++){
            visit[i]= false;
        }
        result+=input(i);
    }

    cout<<result;
    return 0;
}