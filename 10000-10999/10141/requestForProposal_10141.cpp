#include <iostream>
#include <string>
using namespace std;


int main(){

	int requirements, proposals, reqsMet, rfp = 0;
	double price, bestPrice, bestCompliance;
	string proposal, bestProposal, r;
	bool newline = false;
	
	while(cin >> requirements >> proposals && requirements && proposals) {
		if (newline) cout << '\n';
		else newline = true;

		rfp++;
		bestCompliance = 0;
		bestPrice = 999999;
		cin.ignore();

		for(int i=1; i<=requirements; i++) getline(cin, proposal);
		for(int i=1; i<=proposals; i++) {
			getline(cin, proposal);
			cin >> price >> reqsMet;
			if (reqsMet > bestCompliance) {
				bestCompliance = reqsMet;
				bestPrice = price;
				bestProposal = proposal;
			}
			else if (reqsMet == bestCompliance) {
				if (price < bestPrice){
					bestCompliance = reqsMet;
					bestPrice = price;
					bestProposal = proposal;
				}
			}
			cin.ignore();
			while(reqsMet--) getline(cin, proposal);
		}

		cout << "RFP #" << rfp << '\n' << bestProposal << '\n';
	}

	return 0;
}
