#include <iostream>
using namespace std;


int main(){

	int ncases, p;
	bool allSolved;
	cin >> ncases;

	for(int c=1; c<=ncases; c++) {
		allSolved = true;

		for (int i=0; i<13; i++) {
			cin >> p;
			if (p == 0) allSolved = false;
		}
		allSolved ? cout << "Set #" << c << ": Yes\n" : cout << "Set #" << c << ": No\n";
	}
	

	return 0;
}
