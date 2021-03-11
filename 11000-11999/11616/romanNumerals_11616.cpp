#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


typedef struct RomanDigit {
	int value;
	string roman;
} RomanDigit;



int romanToInt(string roman) {
	map<char,int> romanDigits = {
		{'I', 1},	{'V', 5},	{'X', 10},	{'L', 50},
		{'C', 100},	{'D', 500}, {'M', 1000} 
	};

	int value = 0;
	char c, c2;

	for(int i=0; i<roman.length()-1; i++) {
		c = roman[i];	c2 = roman[i+1];
		if (romanDigits[c] < romanDigits[c2]) value -= romanDigits[c];
		else value += romanDigits[c];

	}

	value += romanDigits[roman[roman.length()-1]];
	return value;
}

string intToRoman(int n) {
	vector<RomanDigit> romanValues = {
		{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
		{90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
		{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
	};

	string roman = "";
	int c;
	
	while (n > 0) {
		for (RomanDigit rd : romanValues) {
			c = n / rd.value;
			if (c == 0) continue;
			for(int i=0; i<c; i++) roman += rd.roman;
			n %= rd.value;
		}
	}

	return roman;
}

bool isAllAlpha(string s) {
	for (char c : s) {
		if (! isalpha(c)) return false;
	}
	return true;
}



int main(){

	string line;

	while(getline(cin, line)) {
		if (isAllAlpha(line)) cout << romanToInt(line) << '\n';
		else cout << intToRoman(stoi(line)) << '\n';
	}

	return 0;
}
