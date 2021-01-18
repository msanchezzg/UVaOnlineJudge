#include <iostream>
#include <string>
using namespace std;


string intToBase(int n, int base) {
	string result = "";
	int c = 1;
	int r;
	while (c != 0) {
		c = n / base;
		r = n % base;

		if (r < 0) {	// Negative bases
			r += -base;
			c += 1;
		}
		result = to_string(r) + result;
		n = c;
	}

	return result;
}


int main(){

	int cases, n;
	cin >> cases;
	for (int i=1; i<=cases; i++) {
		cin >> n;
		cout << "Case #" << i << ": " << intToBase(n, -2) << '\n';
	}

	return 0;
}
