#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(){

	map<char,char> characters;
	characters['0'] = '0';
	characters['1'] = '1';
	characters['-'] = '-';
	characters['A'] = characters['B'] = characters['C'] = '2';
	characters['D'] = characters['E'] = characters['F'] = '3';
	characters['G'] = characters['H'] = characters['I'] = '4';
	characters['J'] = characters['K'] = characters['L'] = '5';
	characters['M'] = characters['N'] = characters['O'] = '6';
	characters['P'] = characters['Q'] = characters['R'] = characters['S'] = '7';
	characters['T'] = characters['U'] = characters['V'] = '8';
	characters['W'] = characters['X'] = characters['Y'] = characters['Z'] = '9';

	string line, phone;

	while(cin >> line) {
		phone = "";
		for(char c: line) {
			phone += characters[c];
		}

		cout << phone << "\n";
	}


	return 0;
}
