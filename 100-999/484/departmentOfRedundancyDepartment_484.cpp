#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int main(){

	unordered_map<int,int> numbersAppearences;
	vector<int> insertionOrder;
	int n;

	while(cin >> n) {
		if (numbersAppearences.find(n) != numbersAppearences.end()) numbersAppearences[n]++;
		else {
			numbersAppearences[n] = 1;
			insertionOrder.push_back(n);
		}
	}

	for (int nn : insertionOrder) {
		cout << nn << ' ' << numbersAppearences[nn] << '\n';
	}

	return 0;
}
