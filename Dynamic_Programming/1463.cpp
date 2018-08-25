#include<iostream>

using namespace std;

int DP[1000001]={0};

int main(){
    int N;
	cin>>N;
	
	DP[2]=1;
	DP[3]=1;

	for(int i=4;i<1000001;i++){
		DP[i]=DP[i-1]+1;
		if(i%3==0){
			if(DP[i]>DP[i/3]+1)
				DP[i]=DP[i/3]+1;
		}
		else if(i%2==0)
			if(DP[i]>DP[i/2]+1)
				DP[i]=DP[i/2]+1;
	
	}
	
	cout<<DP[N];
	
    return 0;
}