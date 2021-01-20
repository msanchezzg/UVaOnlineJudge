#include <iostream>
#include <vector>
using namespace std;


int main(){

	int nBanks, nDebentures, reserve;
	int bank1, bank2;
	bool liquidationPossible;
	vector<int> banksReserves;

	while (cin >> nBanks >> nDebentures && nBanks && nDebentures) {
		banksReserves.clear();
		liquidationPossible = true;

		for (int b=1; b<=nBanks; b++) {
			cin >> reserve;
			banksReserves.push_back(reserve);
		}

		// Make transactions between banks
		for (int d=0; d<nDebentures; d++) {
			cin >> bank1 >> bank2 >> reserve;
			banksReserves[bank1-1] -= reserve;
			banksReserves[bank2-1] += reserve;
		}

		// Check final reserves of banks
		for (int b=1; b<=nBanks && liquidationPossible; b++) {
			if (banksReserves[b-1] < 0) liquidationPossible = false;
		}

		liquidationPossible ? cout <<  "S\n" : cout <<  "N\n";
	}
	


	return 0;
}
