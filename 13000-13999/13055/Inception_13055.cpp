#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(){

	int nqueries;
	stack<string> dreams;
	string line, person;

	cin >> nqueries;
	cin.ignore();

	while (nqueries--) {
		getline(cin, line);
		if (line.compare("Test") == 0) {
			if (dreams.empty()) cout << "Not in a dream\n";
			else cout << dreams.top() << endl;
		}
		else if (line.compare("Kick") == 0) {
			if (! dreams.empty()) dreams.pop();
		}
		else {	// "Dream" case
			person = line.substr(6);	// Remove "Dream "
			dreams.push(person);
		}
	}

	return 0;
}
