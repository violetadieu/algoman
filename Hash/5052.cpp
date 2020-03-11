#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(string a,string b){
    return a.length()<b.length();
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin>>T;

    for(int m=0;m<T;m++){
        int num;
        bool flag=true;
        map<string,int>number_list;
        cin>>num;
        vector<string>phone_num;
        for(int k=0;k<num;k++){
            string tmp_num;
            cin>>tmp_num;
            phone_num.push_back(tmp_num);
        }
        sort(phone_num.begin(),phone_num.end(),cmp);
        number_list[phone_num[0]]=1;
        for(int i=1;i<phone_num.size();i++) {
            string now = phone_num[i];
            string tmp = "";
            for (int k = 0; k < now.length(); k++) {
                tmp += now[k];
                if (number_list[tmp] == 1) {
                    flag = false;
                }
            }
            number_list[phone_num[i]] = 1;
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}