#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){

	int cases, n;
	string line, decodedLine, number;
	char character;
	cin >> cases;
	cin.ignore();

	for(int i=1; i<=cases; i++) {
		getline(cin, line);
		number = "";
		decodedLine = "";

		for(char c : line) {
			if (isdigit(c)) {
				number += c;
			}
			else {
				// Decode previous pair char-int
				if (number.length() > 0){
					n = stoi(number);
					for(int j=0; j<n; j++) decodedLine += character;
					number = "";
				}
				character = c;
			}
		}

		if (number.length() > 0){
			n = stoi(number);
			for(int j=0; j<n; j++) decodedLine += character;
		}

		cout << "Case " << i << ": ";
		cout << decodedLine << '\n';

	}

	return 0;
}
