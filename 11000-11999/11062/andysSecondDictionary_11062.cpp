#include <iostream>
#include <set>
#include <string>
using namespace std;


int main(){

	string line, word;
	set<string> words;
	bool inHyphWord = false;

	while(getline(cin, line)) {
		if (! inHyphWord){
			if (word.length() > 0) words.insert(word);
			word = "";
		}
		// Remove '-' if it was an hyphenated word
		else if (word.length() > 0) word = word.substr(0, word.length()-1);

		for (char c : line) {
			if (isalpha(c)) {
				word += tolower(c);
				inHyphWord = false;
			}
			else if (c == '-') {
				inHyphWord = true;
				word += c;
			}
			else {
				if (word.length() > 0) words.insert(word);
				word = "";
				inHyphWord = false;
			}
		}
	}

	if (word.length() > 0) words.insert(word);

	for (string w : words) cout << w << '\n';

	return 0;
}
