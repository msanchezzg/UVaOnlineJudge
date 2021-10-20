#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){

	int numPeople, age;
	vector<int> ages;

	while (cin >> numPeople && numPeople) {
		ages.clear();
		for (int i=0; i<numPeople; i++) {
			cin >> age;
			ages.push_back(age);
		}

		sort(ages.begin(), ages.end());

		for (int i=0; i<numPeople-1; i++) {
			cout << ages[i] << ' ';
		}

		cout << ages[numPeople-1] << '\n';
	}

	return 0;
}
