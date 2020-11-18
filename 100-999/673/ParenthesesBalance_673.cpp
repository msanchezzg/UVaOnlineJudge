#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;


bool isCorrect (string parSequence) {
	stack<char> parentheses;
	map<char,char> pairs = {{')', '('}, {']', '['}};
	char c2;
	for(char c : parSequence) {
		if (c == '(' || c == '[') parentheses.push(c);
		else {	// ')' or ']' case
			if (parentheses.empty()) return false;
			c2 = parentheses.top();
			if (c2 != pairs[c]) return false;
			else parentheses.pop();
		}
	}
	if (parentheses.empty()) return true;
	return false;
}


int main(){

	int n;
	string line;
	cin >> n;
	cin.ignore();

	while (n--) {
		getline(cin, line);
		
		if (isCorrect(line)) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}
