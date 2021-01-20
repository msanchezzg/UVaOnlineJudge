#include <iostream>
#include <set>
using namespace std;


int main(){

	int alice, betty, a, b, c;
	set<int> alicesCards, bettysCards;

	while(cin >> alice >> betty && alice != 0 && betty != 0) {
		alicesCards.clear();
		bettysCards.clear();

		for(int i=0; i<alice; i++) {
			cin >> c;
			alicesCards.insert(c);
		}
		for(int i=0; i<betty; i++) {
			cin >> c;
			bettysCards.insert(c);
		}

		a = alicesCards.size();
		b = bettysCards.size();

		for(int card : alicesCards) {
			if (bettysCards.find(card) != bettysCards.end()) {
				a--;
				b--;
			}
		}

		cout << min(a,b) << '\n';
	}


	return 0;
}
