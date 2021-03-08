#include <iostream>
#include <string>
using namespace std;


int main(){

	int oddPosNums, evenPosNums, total;
	string number, stripNumber;

	while(getline(cin, number)) {
		if (number.length() == 1 && number[0] == '0') break;

		stripNumber = "";
		oddPosNums = 0;
		evenPosNums = 0;

		/* Strip number first */
		for (char c : number) {
			if (! isdigit(c)) continue;
			stripNumber += c;
		}

		/* A number is multiple of 11 if the sum of the numbers in even positions
		minus the sum of numbers in odd positions is a multiple of 11 */
		for (int i=0; i<stripNumber.length(); i+=2) evenPosNums += stripNumber[i] - 48;
		for (int i=1; i<stripNumber.length(); i+=2) oddPosNums += stripNumber[i] - 48;

		total = evenPosNums - oddPosNums;

		if (total % 11 == 0) cout << stripNumber << " is a multiple of 11.\n";
		else cout << stripNumber << " is not a multiple of 11.\n";
	}

	return 0;
}
