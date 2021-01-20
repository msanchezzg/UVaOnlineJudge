#include <iostream>
#include <map>
#include <string>
using namespace std;


int main(){

	map<char, char> numsLetters;
	numsLetters['1'] = 'I'; numsLetters['2'] = 'Z';
	numsLetters['3'] = 'E'; numsLetters['4'] = 'A';
	numsLetters['5'] = 'S'; numsLetters['6'] = 'G';
	numsLetters['7'] = 'T'; numsLetters['8'] = 'B';
	numsLetters['9'] = 'P'; numsLetters['0'] = 'O';

	int cases;
	string line, decodedLine;
	cin >> cases;
	cin.ignore();

	while(getline(cin, line)) {
		decodedLine = "";
		for (char c : line) {
			if (numsLetters.find(c) == numsLetters.end()) decodedLine += c;
			else decodedLine += numsLetters[c];
		}

		cout << decodedLine << '\n';
	}
	

	return 0;
}
