#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
	stack<char>s;
	string bracket;
	int result=0;
	int mul=1;
	int k=0;
	int l=0;
	cin>>bracket;
	for(int i=0;i<bracket.length();i++){
		char n=bracket[i];
		switch(n){
			case '(':
				k++;
				s.push(n);
				mul*=2;
				if(i+1<bracket.length()&&bracket[i+1]==')')
					result+=mul;
				break;
			case '[':
				l++;
				s.push(n);
				mul*=3;
				if(i+1<bracket.length()&&bracket[i+1]==')')
					result+=mul;
				break;
			case ')':
				--k;
				s.pop();
				mul/=2;
				break;
			case ']':
				--l;
				s.pop();
				mul/=3;
				break;
		}
		if (bracket.size()!=0 || l != 0 || k != 0) cout << 0 << endl;
    else cout << result << endl;

	}
	
	return 0;
}