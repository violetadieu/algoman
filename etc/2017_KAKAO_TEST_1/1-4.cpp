#include<iostream>
#include<string>

using namespace std;

struct timetable {
	int hour=24;
	int minute = 00;
};

void chan(timetable &a, timetable &b);

int main() {

	int n=0;//버스 출발 횟수
	int t=0;//간격
	int m=0;//최대 탑승 인원 수
	int can_in = 0;//탑승 인원 가능 수
	int i = 0;//크루 인원 수

	timetable Depart;
	Depart.hour = 9;
	Depart.minute = 0;//첫 출발 시각

	timetable final_arrival;
	final_arrival.hour = 0;
	final_arrival.minute = 0;

	timetable table[2000];

	cin >> n >> t >> m;

	can_in = m;

	while (cin>>table[i].hour) {
		scanf(":%d", &table[i].minute);
		if (table[i].hour > 23 || table[i].minute > 59) {
			cout << "시간 형식 오류 재입력 요망" << endl;
			break;
		}
			i++;
	}

	if (n == 1 && m == 1) {
		final_arrival = Depart;
		cout << final_arrival.hour << ":" << final_arrival.minute << endl;
		exit(1);
	}

	for (int k = 0; k < i - 1; k++) {
		for (int j = 0; j < i - k - 1; j++) {
			chan(table[j], table[j + 1]);
			}
		}

	for (int p = 0; p < i; p++) {
		if (table[p].hour < Depart.hour ||
			(table[p].hour == Depart.hour&&table[p].minute <= Depart.minute)) {
			can_in--;
		}
		else if (table[p].hour > Depart.hour ||
			(table[p].hour == Depart.hour&&table[p].minute >= Depart.minute)) {
			can_in = m;
			n--;
			p--;
			Depart.minute += t;
			if (Depart.minute > 59) {
				Depart.hour++;
				Depart.minute -= 60;
			}
		}

		if ((can_in == 1 && n == 1)||p==(i-1)) {
			if (p == (i - 1)) {
				final_arrival.hour = Depart.hour;
				final_arrival.minute = Depart.minute;
				break;
			}
			else {
				if (table[0].minute == 0) {
					table[0].hour--;
					table[0].minute = 60;
				}
				final_arrival.hour = table[0].hour;
				final_arrival.minute = table[0].minute-1;
				break;
			}
		}

		if (can_in == 0) {
			can_in = m;
			n--;
			Depart.minute += t;
			if (Depart.minute > 59) {
				Depart.hour++;
				Depart.minute -= 60;
			}
		}
	}

	cout << final_arrival.hour << ":" << final_arrival.minute << endl;

		return 0;
	}

void chan(timetable &a, timetable &b) {

	timetable tmp;

	if (a.hour > b.hour) {
		tmp = a;
		a = b;
		b = tmp;
	}
	else if (a.hour == b.hour&&a.minute>b.minute) {
		tmp = a;
		a = b;
		b = tmp;
	}

}