#include <iostream>
using namespace std;


int main(){

	int tea, c, cont;

	while (cin >> tea) {
		cont = 0;
		for (int i=0; i<5; i++) {
			cin >> c;
			if (c == tea) cont ++;
		}
		cout << cont << "\n";
	}
	

	return 0;
}
