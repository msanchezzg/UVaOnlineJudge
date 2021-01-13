#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


bool isVowel(char c) {
	char vowels[] = {'a', 'e', 'i', 'o', 'u'};
	if (find(begin(vowels), end(vowels), c) != end(vowels)) return true;
	return false;
}

bool isMutation(string str1, string str2) {
	if (str1.length() != str2.length()) return false;

	for(int i=0; i<str1.length(); i++) {
		if (str1[i] == str2[i]) continue;
		else if (isVowel(str1[i]) && isVowel(str2[i])) continue;
		else return false;
	}
	return true;
}


int main(){

	int cases;
	string name1, name2;
	cin >> cases;
	cin.ignore();

	while(cases--) {
		getline(cin, name1);
		getline(cin, name2);

		if (isMutation(name1, name2)) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}
