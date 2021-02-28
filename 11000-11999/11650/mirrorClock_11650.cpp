#include <iostream>
#include <string>
using namespace std;


int main(){

	int cases, hour, min, mirrHour, mirrMin;
	string time;
	cin >> cases;
	cin.ignore();

	while(cases--) {
		getline(cin, time);
		hour = stoi(time.substr(0, 2));
		min = stoi(time.substr(3));

		mirrHour = 12 - hour;
		mirrMin = 0 - min;
		if (mirrMin < 0) mirrMin += 60;

		// When it's not minute 00, the hour hand it's not exactly in the number, it has passed it.
		// That reversed results in an hour less
		if (mirrMin != 0) mirrHour--;
		if (mirrHour <= 0) mirrHour += 12;

		printf("%02d:%02d\n", mirrHour, mirrMin);
	}

	return 0;
}
