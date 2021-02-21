#include <iostream>
#include <iomanip>		// hex
#include <string>
using namespace std;


int main(){

	int decimal;
	string number;
	stringstream stream;

	while(getline(cin, number)) {
		if (number[0] == '-') break;

		if (number.size() > 2 && number[1] == 'x') {	// hexadecimal
			decimal = stoul(number, nullptr, 16);
			cout << decimal << '\n';
		}
		else {
			decimal = stoi(number);
			printf("0x%X\n", decimal);
			// cout << hex << decimal << endl;	// Another option
		}
	}

	return 0;
}
