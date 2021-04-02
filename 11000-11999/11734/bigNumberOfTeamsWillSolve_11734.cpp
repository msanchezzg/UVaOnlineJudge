#include <iostream>
#include <string>
using namespace std;


string removeSpaces(string s) {
	string s2 = "";
	for (char c : s) {
		if (c != ' ') s2 += c;
	}
	return s2;
}


int main(){

	int cases;
	string team, teamNoSpaces, judges;
	cin >> cases;
	cin.ignore();

	for (int c=1; c<=cases; c++) {
		getline(cin, team);
		getline(cin, judges);
		teamNoSpaces = removeSpaces(team);
		printf("Case %d: ", c);

		if (teamNoSpaces.compare(judges) == 0) {
			if (teamNoSpaces.length() == team.length()) cout << "Yes\n"; 
			else cout << "Output Format Error\n";
		}
		else cout << "Wrong Answer\n";
	}

	return 0;
}
