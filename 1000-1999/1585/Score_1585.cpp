#include <iostream>
#include <string>
using namespace std;


int main(){

	int ncases, consecutive, total;
	string line;

	cin >> ncases;
	cin.ignore();

	while(ncases--) {
		getline(cin, line);
		consecutive = 0;
		total = 0;
		for (char c: line) {
			if (c == 'O') {
				consecutive++;
				total += (consecutive);
				
			}
			else {
				consecutive = 0;
			}
		}

		cout << total << "\n";
	}
	

	return 0;
}
