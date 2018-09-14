#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int>pw;
int L,C;
void dfs(int i,int vowel,int cons,string str){
    if(str.length()==L){
        if(vowel>=1&&cons>=2)
            cout<<str<<endl;
        return;
    }
    for(int k=i;k<C;k++){
        if(pw[k]==(int)'a'||pw[k]==(int)'e'||pw[k]==(int)'i'||pw[k]==(int)'o'||pw[k]==(int)'u'){
            dfs(k+1,vowel+1,cons,str+(char)pw[k]);
        }
        else
            dfs(k+1,vowel,cons+1,str+(char)pw[k]);

    }
}

int main(){
    cin>>L>>C;//L==암호의 길이
    for(int i=0;i<C;i++){
        char a;
        cin>>a;
        pw.push_back((int)a);//총합
    }
    //정렬
    sort(pw.begin(),pw.end());

    dfs(0,0,0,"");

    return 0;
}