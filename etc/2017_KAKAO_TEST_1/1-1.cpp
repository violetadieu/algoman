#include<iostream>
#include<string>


using namespace std;

int main() {

	int n=0;//1<=n<=16
	int arr1[16] = { 0, }, arr2[16] = { 0, };
	int change[8] = { 0, }, imsi[8] = { 0, };

	cout << "n 입력:";
	cin >> n;
	cout << endl;
	cout << "arr1입력:";
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	cout << "arr2입력:";
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}

	for (int i = 0; i < 5; i++) {
		int c = arr1[i] | arr2[i];
		int p;
		for (int k = 0; k < 5; k++) {
			p = c % 2;
			c = c / 2;
			change[i] = p;
			imsi[ - k] = change[i];
		}
		for (int m = 0; m < 5; m++) {
			if (imsi[m] == 0) {
				cout << " ";
			}
			else
				cout << "#";
		}
		cout << endl;
	}
	return 0;
}