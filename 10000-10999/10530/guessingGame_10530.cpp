#include <iostream>
#include <string>
#include <set>
using namespace std;


int main(){

	int n;
	string word1, word2;
	bool dishonest = false;
	set<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	while (cin >> n && n) {
		cin >> word1 >> word2;

		if (word1[0] == 'r') {	// right on
			if (numbers.find(n) == numbers.end()) cout << "Stan is dishonest\n";
			else cout << "Stan may be honest\n";

			numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			dishonest = false;
		}
		else if (word2[0] == 'h') {	// too high
			for(int i=n; i<=10; i++) numbers.erase(i);
		}
		else if (word2[0] == 'l') {	// too low
			for(int i=1; i<=n; i++) numbers.erase(i);
		}
	}

	return 0;
}
