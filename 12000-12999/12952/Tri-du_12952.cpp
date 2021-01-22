#include <iostream>
using namespace std;


int main(){

	int card1, card2, card3;

	while(cin >> card1 >> card2) {
		card3 = max(card1, card2);
		cout << card3 << '\n';
	}

	return 0;
}
