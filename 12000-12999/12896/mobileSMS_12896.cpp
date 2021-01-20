#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main(){

	map<int,vector<char>> keysLetters;
	keysLetters[1] = {'.', ',', '?', '"'};
	keysLetters[2] = {'a', 'b', 'c'};
	keysLetters[3] = {'d', 'e', 'f'};
	keysLetters[4] = {'g', 'h', 'i'};
	keysLetters[5] = {'j', 'k', 'l'};
	keysLetters[6] = {'m', 'n', 'o'};
	keysLetters[7] = {'p', 'q', 'r', 's'};
	keysLetters[8] = {'t', 'u', 'v'};
	keysLetters[9] = {'w', 'x', 'y', 'z'};
	keysLetters[0] = {' '};

	vector<int> keys;
	vector<int> pulsations;

	int cases, characters, c, p;
	char letter;
	cin >> cases;
	while(cases--) {
		keys.clear();
		pulsations.clear();
		cin >> characters;

		for (int i = 0; i < characters; i++) {
			cin >> c;
			keys.push_back(c);
		}
		for (int i = 0; i < characters; i++) {
			cin >> c;
			pulsations.push_back(c);
		}
		for (int i = 0; i < characters; i++) {
			c = keys[i];
			p = pulsations[i];
			letter = keysLetters[c][p-1];
			cout << letter;
		}
		cout << '\n';
		
	}


	return 0;
}
