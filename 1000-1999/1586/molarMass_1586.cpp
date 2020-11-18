#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;


int main(){

	int ncases, num;
	double total;
	char elem;
	string line, numbers;
	stack<char> elements;
	map<char, double> molarMasses = {{'C', 12.01}, {'H', 1.008}, {'O', 16.00}, {'N', 14.01}};
	bool previousNumbers;

	cin >> ncases;
	cin.ignore();

	while(ncases--) {
		getline(cin, line);
		total = 0;
		elements = stack<char>();
		numbers = "";
		previousNumbers = false;

		for (char c: line) {
			if (isdigit(c)) {
				numbers += c;
				previousNumbers = true;
			}
			else if (isalpha(c)) {
				if (previousNumbers) {
					num = stoi(numbers);
					numbers = "";

					elem = elements.top();
					elements.pop();
					total += (molarMasses[elem]*num);
				}
				elements.push(c);
				previousNumbers = false;
			}
		}

		if (previousNumbers) {
			elem = elements.top();
			elements.pop();
			num = stoi(numbers);
			total += (molarMasses[elem]*num);
		}
		while (! elements.empty()) {
			elem = elements.top();
			elements.pop();
			total += (molarMasses[elem]);
		}

		printf("%.3lf\n", total);
	}
	

	return 0;
}
