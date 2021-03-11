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


void resetRomanCharsOccurrences(map<char,int>& ocurrences) {
	ocurrences.clear();
	ocurrences['I'] = ocurrences['V'] = ocurrences['X'] = 
	ocurrences['L'] = ocurrences['D'] = ocurrences['C'] = ocurrences['M'] = 0;
}

int main(){

	int n;
	map<char,int> romanCharsOccurrences;
	string roman;

	while(cin >> n && n) {
		resetRomanCharsOccurrences(romanCharsOccurrences);

		for(int i=1; i<=n; i++) {
			roman = intToRoman(i);

			for(char c : roman) romanCharsOccurrences[c]++;
		}

		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n,
			romanCharsOccurrences['I'], romanCharsOccurrences['V'],
			romanCharsOccurrences['X'], romanCharsOccurrences['L'],
			romanCharsOccurrences['C']
		);
	}

	return 0;
}
