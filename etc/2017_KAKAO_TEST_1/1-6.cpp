#include<iostream>
#include<string>
#include<vector>

using namespace std;

void resize(string s,int n);
int del(vector<string>&v,int &count,int length);
bool delet(vector<string>&v, int i, int p,int &c);
void realign(vector<string> &v, int length);

int main() {

	int m = 0;
	int n = 0;
	int count = 0;//지워진 블록 갯수

	string block;
	vector<string>board;

	cin >> m;//줄 갯수

	board.resize(m);

	cin >> n;//한줄 크기

	for (int i = 0; i < m; i++) {
		cin >> block;
		resize(block, n);
		board[i] = block;
	}
	while (1) {
		realign(board,n);
		if (del(board, count, n) == 0)
			break;
	}
	cout << count << endl;
	return 0;
}

void resize(string s, int n)
{
	for (int k = n; k < s.size(); k++) {
		s[k] = NULL;
	}
}

int del(vector<string> &v, int &count,int length)
{
	int c = 0;
	for (int i = 0; i < v.size()-1; i++) {
		for (int p = 0; p < length-1; p++) {
			delet(v, i, p, c);
		}
	}
	count += c;
	return c;
}

bool delet(vector<string> &v,int i,int p, int &c)
{
	if (v[i][p] != ' '&& v[i][p] == v[i + 1][p]
		&& v[i][p] == v[i][p + 1]
		&& v[i][p] == v[i + 1][p + 1]) {
		v[i][p] = ' ';
		c++;
		if (i+2 < v.size()) {
			if (delet(v, i + 1, p, c) == true&&v[i + 1][p] != ' ') {
				v[i + 1][p] = ' ';
				c++;
			}
			if (delet(v, i, p + 1, c) == true&& v[i][p + 1] != ' ') {
				v[i][p + 1] = ' ';
				c++;
			}
			if (delet(v, i + 1, p + 1, c) == true&& v[i + 1][p + 1] != ' ') {
				v[i + 1][p + 1] = ' ';
				c++;
			}
		}
		else if (i + 2 == v.size()) {
			v[i + 1][p] = ' ';
			v[i][p + 1] = ' ';
			v[i + 1][p + 1] = ' ';
			c+=3;
		}
	}
	else
		return true;
}

void realign(vector<string> &v,int length)
{
	for (int i = 0; i < v.size() - 1; i++) {
		for (int p = 0; p < length - 1; p++) {
			if (v[i + 1][p] == ' ') {
				v[i + 1][p] = v[i][p];
				v[i][p] = ' ';
			}
		}
	}
}
