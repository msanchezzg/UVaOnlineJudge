#include <iostream>
#include <vector>
#include <string>
using namespace std;


int sumOfDigits(int n) {
	string s = to_string(n);
	int total = 0;
	for (char c : s) total += c - 48;	// 48 is ASCII value of 0
	return total;
}

int main(){

	int cases, oddNumsSum, pairNumsSum, total, n, n2;
	string s, card;
	bool oddPosition;
	vector<string> creditCard;
	cin >> cases;
	cin.ignore();

	while(cases--) {
		getline(cin, card);
		creditCard.clear();
		oddNumsSum = 0;
		pairNumsSum = 0;
		oddPosition = false;

		for(char num : card) {
			if (! isdigit(num)) continue;
			if (oddPosition) {
				n = num - 48;
				oddNumsSum += n;
			}
			else {
				n = num - 48;
				n2 = n*2;
				pairNumsSum += sumOfDigits(n2);
			}
			oddPosition = !oddPosition;
		}

		total = pairNumsSum + oddNumsSum;
		s = to_string(total);
		if (s[s.length()-1] == '0') cout << "Valid\n";
		else cout << "Invalid\n";
	}


	return 0;
}
