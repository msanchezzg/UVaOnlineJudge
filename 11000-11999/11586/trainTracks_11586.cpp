#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){

	int cases, countM, countF;
	string trains;
	cin >> cases;
	cin.ignore();

	while(cases--) {
		getline(cin, trains);
		countM = count(trains.begin(), trains.end(), 'M');
		countF = count(trains.begin(), trains.end(), 'F');

		if (countM == countF && countM != 1 && countF != 1) cout << "LOOP\n";
		else cout << "NO LOOP\n";
	}

	return 0;
}
