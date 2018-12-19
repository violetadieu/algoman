#include <iostream>
using namespace std;
int main(void)
{
	int n, arr[1000], clusterSize;
	long long cluster = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> clusterSize;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % clusterSize == 0)
			cluster += arr[i] / clusterSize;
		else
			cluster += arr[i] / clusterSize + 1;
	}
	cout << cluster*(long long)clusterSize;
}
