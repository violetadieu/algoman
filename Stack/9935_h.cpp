#include <iostream>
#include <string>
using namespace std;

char result[1000001];
int main()
{
	string str, bomb;
	cin >> str >> bomb; //str을 result에 bomb를 뺀 나머지 문자열을 넣을것이다.
	int index = 0;
	for (int i = 0; i < str.size(); i++)
	{
		result[index++] = str[i];
		int j = (int)bomb.size();
		if (str[i] == bomb[--j]) //c4중 4부터 비교를 시작한다.
		{
			bool check = false;
			int size = index - (int)bomb.length();
			for (int k = index - 1; k >= size; k--)
			{
				if (result[k] == bomb[j--])
				{
					check = true;
				}
				else
				{
					check = false;
					break;
				}
			}

			if (check) index -= bomb.size();
		}


	}
	if (index == 0)
		cout << "FRULA" << endl;
	else
	{
		for (int i = 0; i < index; i++)
			cout << result[i];
		cout << endl;
	}


	return 0;
}
