#include <iostream>
using namespace std;


int main(){

	int x1, y1, x2, y2, diff1, diff2, moves;

	while (cin >> x1 >> y1 >> x2 >> y2) {
		if (!x1 && !y1 && !x2 && !y2) break;

		diff1 = abs(x1 - x2);
		diff2 = abs(y1 - y2);

		if (diff1 == 0 && diff2 == 0) moves = 0;
		else if (diff1 == 0 || diff2 == 0) moves = 1;
		else if (diff1 == diff2) moves = 1;
		else moves = 2;

		cout << moves << '\n';
	}

	return 0;
}
