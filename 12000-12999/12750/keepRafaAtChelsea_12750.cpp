#include <iostream>
using namespace std;


int main(){
	
	int cases, games, cont, loseCont;
	char result;
	bool out;
	cin >> cases;

	for(int i=1; i<=cases; i++) {
		cin >> games;
		cont = 0;
		loseCont = 0;
		out = false;
		for(int j=0; j<games; j++) {
			cin >> result;
			if (out) continue;
			cont++;
			if (result != 'W') loseCont++;
			else loseCont = 0;
			if (loseCont >= 3) out = true;
		}

		printf("Case %d: ", i);
		out ? cout << cont << '\n' : cout << "Yay! Mighty Rafa persists!\n";
	}


	return 0;
}
