#include<iostream>
#include<string>
#include<set>
#include<ctype.h>
#include<algorithm>
#include<vector>

using namespace std;

void input(string &s, multiset<string> &m);//다중집합 원소 만들기
double J(multiset<string>a, multiset<string>b);//다중집합 2개 비교 및
//자카드 유사도 구하기
int count(vector<string> m);

int main() {

	string A;
	multiset<string> a;
	string B;
	multiset<string> b;

	cin >> A;

	cin >> B;

	input(A, a);
	input(B, b);

	cout << floor(J(a, b)*65536)<<endl;

	return 0;
}

void input(string &s, multiset<string> &m) {

	string tmp="AA";

	for (int i = 0; i < s.size()-1; i++) {
		if (isalpha(s[i]) != 0 && isalpha(s[i + 1]) != 0) {
			tmp[0] = s[i];
			tmp[1] = s[i + 1];
			m.insert(tmp);
		}
	}

}

double J(multiset<string>a, multiset<string>b) {

	double total_min=0;//교집합
	double total_max = 0;//합집합
	if (a.size() == 0 && b.size() == 0)
		return 1;

	vector<string>v(100);

	for (int i = 0; i < v.size(); i++) {
		v[i] = " ";
	}

	set_intersection(a.begin(), a.end(),b.begin(),b.end(),v.begin());
	total_min = count(v);

	set_union(a.begin(), a.end(), b.begin(), b.end(), v.begin());
	total_max = count(v);

	return total_min / total_max;
}

int count(vector<string> m) {
	int result = 0;
	for (int i = 0; i < m.size(); i++) {
		if (m[i] != " ") {
			result++;
		}
	}
	return result;
}