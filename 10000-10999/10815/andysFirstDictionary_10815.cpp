#include <iostream>
#include <set>
#include <string>
using namespace std;


int main(){

	string line, word;
	set<string> words;

	while(getline(cin, line)) {
		if (word.length() > 0) words.insert(word);
		word = "";

		for (char c : line) {
			if (isalpha(c)) word += tolower(c);
			else {
				if (word.length() > 0) words.insert(word);
				word = "";
			}
		}
	}

	if (word.length() > 0) words.insert(word);

	for (string w : words) cout << w << '\n';

	return 0;
}
