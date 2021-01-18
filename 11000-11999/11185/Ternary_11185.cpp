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

	int n;
	while (cin >> n and n >= 0) {
		cout << intToBase(n, 3) << '\n';
	}

	return 0;
}
