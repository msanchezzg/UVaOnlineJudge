#include <iostream>
using namespace std;


int main(){

	int ncases, d, prev;
	bool order;
	cin >> ncases;

	while(ncases--) {
		order = true;
		cin >> prev;
		for (int i=1; i<5; i++) {
			cin >> d;
			if (d == (prev+1)) prev = d;
			else order = false;
		}
		order ? cout << "Y\n" : cout << "N\n";
	}
	

	return 0;
}
