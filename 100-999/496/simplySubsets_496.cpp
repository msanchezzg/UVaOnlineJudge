#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <string>
using namespace std;


int main(){

	int n;
	string line1, line2;
	set<int> set1, set2, aux;

	while (getline(cin, line1) && getline(cin, line2)) {
		istringstream is1(line1);
		set1.clear();
		while (is1 >> n) set1.insert(n);

		istringstream is2(line2);
		set2.clear();
		while (is2 >> n) set2.insert(n);

		aux.clear();
		if (set1 == set2) {
			cout << "A equals B\n";
			continue;
		}

		if (includes(set1.begin(), set1.end(), set2.begin(), set2.end())) {
			cout << "B is a proper subset of A\n";
			continue;
		}

		if (includes(set2.begin(), set2.end(), set1.begin(), set1.end())) {
			cout << "A is a proper subset of B\n";
			continue;
		}

		aux.clear();
		set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(aux, aux.begin()));
		if (aux.empty()) {
			cout << "A and B are disjoint\n";
			continue;
		}

		cout << "I'm confused!\n";

	}

	return 0;
}
