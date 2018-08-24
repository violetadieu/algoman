#include <iostream>

using namespace std;
int DP[41][2]={0,};

int main(int argc, char* argv[]) {
	int N;
	int value=0;
	cin>>N;
	DP[0][0]=1;//fibo[0]이 출력하는 0
	DP[1][1]=1;
	for(int i=2;i<=40;i++){
		DP[i][0]=DP[i-2][0]+DP[i-1][0];
		DP[i][1]=DP[i-2][1]+DP[i-1][1];
	}
	for(int i=0;i<N;i++){
		cin>>value;
		cout<<DP[value][0]<<" "<<DP[value][1]<<endl;
	}
	return 0;
}