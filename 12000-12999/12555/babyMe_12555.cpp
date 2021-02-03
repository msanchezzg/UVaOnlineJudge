#include <iostream>
#include <string>
using namespace std;


int main(){

	int cases, n1, n2;
	double t;
	string line, number1, number2, total;
	bool number1Completed;
	cin >> cases;
	cin.ignore();

	for (int i = 1; i <= cases; i++) {
		getline(cin, line);
		number1Completed = false;
		number1 = "";
		number2 = "";
		n2 = 0;
		for(char c: line) {
			if (isdigit(c) && !number1Completed) number1 += c;
			else if (isdigit(c)) number2 += c;
			else {
				number1Completed = true;
			}
		}

		n1 = stoi(number1);
		if (number2.length() != 0) n2 = stoi(number2);
		t = 0.5*n1 + 0.05*n2;
		total = to_string(t);
		// cout << "Case " << i << ": " << total << "\n";
		printf("Case %d: %g\n", i, t);

	}
	

	return 0;
}
