#include <iostream>

using namespace std;

int main()
{
	int a[4] = { 0, };
	int b[2];
	int MAX = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int n = 0; n < 2; n++)
		{
			cin >> b[n];
		}
		b[0] *= (-1);
		if (i == 0)
			a[i] = b[0] + b[1];
		else
		a[i] =a[i-1]+ b[0] + b[1];
	}
	for (int i = 0; i < 4; i++)
	{
		if (a[i] > MAX)
			MAX = a[i];
	}
	cout << MAX;
	cout << endl;
	return 0;
}
