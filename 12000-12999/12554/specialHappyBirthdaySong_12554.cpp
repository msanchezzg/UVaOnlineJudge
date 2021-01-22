#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;


int main(){

	vector<string> people;
	vector<string> song = {
		"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"
	};

	int numPeople, numVersesToSing;
	int songVerses = 16;
	string name, verse;

	cin >> numPeople;
	for(int i=0; i<numPeople; i++) {
		cin >> name;
		people.push_back(name);
	}

	numVersesToSing = ceil(numPeople / double(songVerses)) * songVerses;

	for(int i=0; i<numVersesToSing; i++) {
		name = people[i % numPeople];
		verse = song[i % songVerses];

		cout << name << ": " << verse << '\n';
	}
	
	return 0;
}
