#include<iostream>

using namespace std;
int a[500001]={0,};
int b[500001]={0,};
int main(){
	int n;
	int max=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>max){
			max=a[i];
			cout<<"0 ";
		}
		else{
			int tmp=i-1;
			for(;a[tmp]<a[i];tmp=b[tmp]);
			b[i]=tmp;
			cout<<tmp;
		}
			
	}
	
	return 0;
}