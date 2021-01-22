#include <iostream>
using namespace std;


int main(){

	int nPlayers, nMatches, goals, total;
	bool hasScoredInAll;

	while(cin >> nPlayers >> nMatches) {
		total = 0;

		for(int p=0; p<nPlayers; p++) {
			hasScoredInAll = true;
			for(int m=0; m<nMatches; m++) {
				cin >> goals;
				if (goals == 0) hasScoredInAll = false;
			}
			if (hasScoredInAll) total++;
		}

		cout << total << '\n';
	}

	return 0;
}
