#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main(){

	int cases, n, cost, charCount;
	char c;
	double total;
	map<char, int> paidChars;
	string line;

	cin >> cases;
	while(cases--) {
		paidChars.clear();
		total = 0;
		cin >> n;
		while (n--) {
			cin >> c >> cost;
			paidChars[c] = cost;
		}
		cin >> n;
		cin.ignore();
		while(n--) {
			getline(cin, line);
			for(auto const& x: paidChars) {
				charCount = count(line.begin(), line.end(), x.first);
				total += charCount*x.second;
			}
		}

		printf("%.2lf$\n", total/100.0);
	}

	return 0;
}
