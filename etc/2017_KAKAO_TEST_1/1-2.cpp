#include<iostream>
#include<string>

using namespace std;

int main() {
 	string Score="10D2S0T";
	int first_result=0;
	int second_result = 0;
	int final_result = 0;
	int i = 0;

	//cin >> Score;


	while (i<Score.size()+1) {
		switch (Score[i])
		{
		case'0':
			first_result = 0;
			i++;
			break;

		case '1':
		{
			if (Score[i + 1] == '0')
			{
				first_result = 10;
				i = i + 2;
				break;
			}
			else
				first_result = 1;
			i++;
			break;//1 or 10
		}
		case '2':
			first_result = 2;
			i++;
			break;
		case '3':
			first_result = 3;
			i++;
			break;
		case '4':
			first_result = 4;
			i++;
			break;
		case '5':
			first_result = 5;
			i++;
			break;
		case '6':
			first_result = 6;
			i++;
			break;
		case '7':
			first_result = 7;
			i++;
			break;
		case '8':
			first_result = 8;
			i++;
			break;
		case '9':
			first_result = 9;
			i++;
			break;

		case 'S':
			
			if (Score[i + 1] == '#' || Score[i + 1] == '*') {
				i++;
				break;
			}
			else {
				final_result += second_result;
			}
			second_result = first_result;
			i++;
			break;//single

		case 'D':
			first_result =first_result*first_result;
			if (Score[i + 1] == '#' || Score[i + 1] == '*') {
				i++;
				break;
			}
			else {
				final_result += second_result;
			}
			i++;
			second_result = first_result;
			break;//Double

		case 'T':
			first_result = first_result*first_result*first_result;
			
			if (Score[i + 1] == '#' || Score[i + 1] == '*') {
				i++;
				break;
			}
			else {
				final_result += second_result;
			}
			second_result = first_result;
			i++;
			break;//Triple

		case '*':
			first_result *= 2;
			second_result *= 2;
			final_result +=second_result;
			second_result = first_result;
			i++;
			break;

		case '#':
			first_result *= -1;
			final_result +=second_result;
			second_result = first_result;
			i++;
			break;
		default:
			final_result += second_result;
			i++;
			break;
		}
	}

	cout << final_result << endl;

	return 0;
}