#include <iostream>
using namespace std;


bool isLeapYear(int year) {
	if (year % 400 == 0) return true;
	if(year % 100 == 0) return false;
	if(year % 4 == 0)  return true;
	return  false;
}

int main(){

	int ncases, day, month, year, year2, birthdays;
	cin >> ncases;
	for (int c=1; c<=ncases; c++) {
		cin >> day >> month >> year >> year2;
		if (day != 29 || month != 2) birthdays = year2 - year;
		else {
			birthdays = 0;
			for (int i=year+4; i<=year2; i+=4) {
				if (isLeapYear(i)) birthdays++;
			}
		}

		cout << "Case " << c << ": " << birthdays << "\n";
	}

	return 0;
}
