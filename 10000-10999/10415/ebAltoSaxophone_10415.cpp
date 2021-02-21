#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;


class Button {
	public:
		bool lastPressed;
		int numPresses;

		Button() {
			lastPressed = false;
			numPresses = 0;
		}

		void reset() {
			lastPressed = false;
			numPresses = 0;
		}
};


void resetButtons(vector<Button> &buttons) {
	for (int i = 0; i<buttons.size(); i++) {
		Button *b = &buttons[i];
		(*b).reset();
	}
}


int main(){

	map<char, set<int>> notesFingers = {
		{'c', {2, 3, 4, 7, 8, 9, 10}},
		{'d', {2, 3, 4, 7, 8, 9}},
		{'e', {2, 3, 4, 7, 8}},
		{'f', {2, 3, 4, 7}},
		{'g', {2, 3, 4}},
		{'a', {2, 3}},
		{'b', {2}},
		{'C', {3}},
		{'D', {1, 2, 3, 4, 7, 8, 9}},
		{'E', {1, 2, 3, 4, 7, 8}},
		{'F', {1, 2, 3, 4, 7}},
		{'G', {1, 2, 3, 4}},
		{'A', {1, 2, 3}},
		{'B', {1, 2}},
	};

	vector<Button> buttons;
	for(int i=0; i<10; i++) buttons.push_back(Button());

	set<int> noteButtons;
	string song;
	int cases;
	cin >> cases;
	cin.ignore();

	while(cases--) {
		resetButtons(buttons);

		getline(cin, song);

		for(char note : song) {
			noteButtons = notesFingers[note];

			for(int i=0; i<10; i++) {
				if (noteButtons.count(i+1)) {
					if (! buttons[i].lastPressed) {
						buttons[i].lastPressed = true;
						buttons[i].numPresses++;
					}
				}
				else {
					buttons[i].lastPressed = false;
				}
			}
		}

		for(int i=0; i<9; i++) cout << buttons[i].numPresses << ' ';
		cout << buttons[9].numPresses << '\n';
	}

	return 0;
}
