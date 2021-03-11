#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


typedef struct RomanDigit {
	int value;
	string roman;
} RomanDigit;

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

int getMatches(string roman) {
	map<char,int> romanDigitMatches = {
		{'M', 4}, {'C', 2}, {'D', 3},
		{'L', 2}, {'X', 2}, {'V', 2}, {'I', 1}, 
	};
	int matches = 0;

	for (char c : roman) { matches += romanDigitMatches[c]; }

	return matches;
}


int main(){

	int n;

	while(cin >> n) {
		cout << getMatches(intToRoman(n)) << '\n';
	}

	return 0;
}
