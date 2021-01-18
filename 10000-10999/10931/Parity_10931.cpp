#include <iostream>
#include <algorithm>
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

	int n, numOfOnes;
	string binary;
	
	while (cin >> n && n > 0) {
		binary = intToBase(n, 2);
		numOfOnes = count(binary.begin(), binary.end(), '1');
		cout << "The parity of " << binary << " is " << numOfOnes << " (mod 2).\n";
	}

	return 0;
}
