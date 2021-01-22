#include <iostream>
using namespace std;


int main(){

	int cases, nColumns, col, row, diff, diff2;
	bool gapClosed;

	cin >> cases;
	while(cases--) {
		cin >> nColumns;
		gapClosed = true;

		cin >> col >> row;
		diff = row-col;

		for(int i=0; i<nColumns-1; i++) {
			cin >> col >> row;
			diff2 = row-col;
			if (diff != diff2) gapClosed = false;
		}

		gapClosed ? cout << "yes\n" : cout << "no\n";
		if (cases >= 1) cout << '\n';
	}

	return 0;
}
