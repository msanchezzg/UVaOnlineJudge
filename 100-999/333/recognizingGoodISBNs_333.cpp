#include <iostream>
#include <string>
#include <vector>
using namespace std;


string strip(string s) {
	int firstChar = 0;
	int lastChar = s.length() - 1 ;
	while(s[firstChar] == ' ') firstChar++;
	while(s[lastChar] == ' ') lastChar--;

	string stripStr = s.substr(firstChar, lastChar-firstChar+1);
	return stripStr;
}

bool isCorrectISBN(string s) {
	int digitCounter = 0;
	char c;
	vector<int> digits;

	// Check valid characters
	for (int i=0; i<s.length(); i++) {
		c = s[i];
		if (c == '-' || c == ' ') continue;
		if (isdigit(c)) {
			digitCounter++;
			if (digitCounter > 10) return false;
			digits.push_back(c-48);
		}
		else if (c == 'X') {
			digitCounter++;
			if (digitCounter != 10) return false;	// 'X' is only allowed as last digit
			digits.push_back(10);
		}
		else return false;
	}
	if (digitCounter != 10) return false;

	// Compute partial sums
	vector<int> s1;
	int partialSum = 0;

	for (int d : digits) {
		partialSum += d;
		s1.push_back(partialSum);
	}

	int s2 = 0;
	for (int d : s1) {
		s2 += d;
	}

	return (s2 % 11 == 0);
}


int main(){

	string ISBN, stripISBN;

	while(getline(cin, ISBN)) {
		stripISBN = strip(ISBN);
		isCorrectISBN(stripISBN) ?
			cout << stripISBN << " is correct.\n" :
			cout << stripISBN << " is incorrect.\n";
	}

	return 0;
}
