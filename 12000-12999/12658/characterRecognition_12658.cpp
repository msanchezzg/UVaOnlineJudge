#include <iostream>
#include <string>
using namespace std;

/**
 * Numbers:
 * 
 * 		.*.		***		***
 * 		.*.		..*		..*
 * 		.*.		***		***
 * 		.*.		*..		..*
 * 		.*.		***		***
 */

int main(){

	int nNums, lineLen;
	int numberLen = 3;
	string line, num;
	string result = "";
	cin >> nNums;
	lineLen = nNums*4;
	cin.ignore();

	for(int i=0; i<4; i++) {
		getline(cin, line);
	}

	for (int j=0; j<lineLen; j+=numberLen+1) {
		num = line.substr(j, numberLen);
		if (num[0] == '*')	result += '2';
		else if (num[1] == '*')	result += '1';
		else if (num[2] == '*')	result += '3';
	}

	cout << result << '\n';

	getline(cin, line);

	return 0;
}
