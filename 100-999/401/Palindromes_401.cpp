#include <iostream>
#include <map>
#include <string>
using namespace std;


bool isMirroredString(string s) {
	map<char,char> reverseChars = {
		{'A', 'A'},	{'E', '3'},	{'H', 'H'}, {'I', 'I'},
		{'J', 'L'},	{'L', 'J'}, {'M', 'M'},	{'O', 'O'},
		{'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'},
		{'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'},
		{'1', '1'}, {'2', 'S'}, {'3', 'E'}, {'5', 'Z'},	{'8', '8'},
	};

	char c1, c2;
	for(int i=0; i<=s.length()/2; i++) {
		c1 = s[i];
		c2 = s[s.length()-i-1];
		if (reverseChars[c1] != c2) return false;
	}

	return true;
}

bool isPalindromeString(string s) {
	char c1, c2;
	for(int i=0; i<=s.length()/2; i++) {
		c1 = s[i];
		c2 = s[s.length()-i-1];
		if (c1 != c2) return false;
	}

	return true;
}


int main(){

	string s;
	bool isPal, isMirr;

	while(getline(cin, s)) {
		isPal = isPalindromeString(s);
		isMirr = isMirroredString(s);

		if (isPal && isMirr) cout << s << " -- is a mirrored palindrome.\n\n";
		else if (isPal) cout << s << " -- is a regular palindrome.\n\n";
		else if (isMirr) cout << s << " -- is a mirrored string.\n\n";
		else cout << s << " -- is not a palindrome.\n\n";
	}

	return 0;
}
