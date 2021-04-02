#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;


bool cmp(pair<char,int> &p1, pair<char,int> &p2) {
	return p1.second > p2.second;
}


vector<pair<char,int>> charsFrequencies(string s) {
	vector<pair<char,int>> freq;

	for(char c : s) {
		auto it = find_if( freq.begin(), freq.end(),
    		[&c](pair<char, int>& element){ return element.first == c;} );

		if (it == freq.end()) freq.push_back(make_pair(c, 1));
		else freq[it-freq.begin()].second++; 
	}

	return freq;
}


vector<char> getKeys(vector<pair<char,int>> v) {
	vector<char> keys;

	for (pair<char,int> p : v) {
		keys.push_back(p.first);
	}

	return keys;
}

int main(){

	int cases, index;
	string line1, line2, decodedLine;
	vector<pair<char,int>> freqLine1, freqLine2;
	vector<char> keysLine1, keysLine2;

	cin >> cases;
	cin.ignore();
	while (cases--) {
		getline(cin, line1);

		getline(cin, line1);
		freqLine1 = charsFrequencies(line1);
		sort(freqLine1.begin(), freqLine1.end(), cmp);
		keysLine1 = getKeys(freqLine1);

		getline(cin, line2);
		freqLine2 = charsFrequencies(line2);
		sort(freqLine2.begin(), freqLine2.end(), cmp);
		keysLine2 = getKeys(freqLine2);

		decodedLine = "";
		for (char c : line2) {
			index = find(keysLine2.begin(), keysLine2.end(), c) - keysLine2.begin();
			decodedLine += keysLine1[index];
		}

		cout << decodedLine << "\n";
		if (cases > 0) cout << '\n';
	}

	return 0;
}
