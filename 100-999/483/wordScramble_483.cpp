#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(){

	int nwords;
	string line, word;
	bool inWord = false;
	
	while (getline(cin, line)) {
		if (line.length() == 0) {
			cout << '\n';
			continue;
		}
		word = "";
		inWord = false;
		for (char c: line) {
			if (c == ' ') {
				if (inWord) {
					reverse(word.begin(), word.end());
					cout << word;
					word = "";
					inWord = false;
				}
				cout << c;
			}
			else {
				inWord = true;
				word += c;
			}
		}
		if (inWord) {
			reverse(word.begin(), word.end());
			cout << word;
		}
		cout << '\n';
	}


	return 0;
}
