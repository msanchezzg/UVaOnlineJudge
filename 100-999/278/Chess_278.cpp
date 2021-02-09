#include <iostream>
#include <cmath>
using namespace std;

/*
 * Max number of rooks = min(rows, cols)
 * Max number of knights = ceil((rows*cols)/2)
 * Max number of Kings = ceil(rows/2) * ceil(cols/2)
 * Max number of Queens = min(rows, cols)
 */ 


int main(){

	int cases, rows, cols, m;
	char piece;
	cin >> cases;

	while (cases--) {
		cin >> piece >> rows >> cols;

		switch (piece) {
		case 'r': case 'Q':
			m = min(rows, cols);
			break;
		case 'k':
			m = ceil(rows*cols/2.0);
			break;
		case 'K':
			m = ceil(rows/2.0) * ceil(cols/2.0);
			break;
		default:
			m = 0;
			break;
		}

		cout << m << '\n';
	}

	return 0;
}
