#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main(){
	int DP[12]={0,};
	int cnt;
	cin>>cnt;
	DP[0]=0;
	DP[1]=1;
	DP[2]=2;
	DP[3]=4;
	for(int i=4;i<12;i++)
		DP[i]=DP[i-3]+DP[i-2]+DP[i-1];
	while(cnt--){
		int n;
		cin>>n;
		cout<<DP[n]<<endl;
	}
	
	
    return 0;
}