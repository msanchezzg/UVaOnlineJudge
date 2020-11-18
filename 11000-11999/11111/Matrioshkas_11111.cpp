#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
using namespace std;


bool isCorrect (vector<int> toys) {
	stack<int> matrioshka;
	map<int,int> adds;
	int i2, parent;
	for(int i : toys) {
		// cout <<"number in sequence: " <<i<<endl;
		// if (! matrioshka.empty()) cout << "top of stack: " <<matrioshka.top() <<endl;
		// else cout << "top of stack: -" <<endl;
		// cout << "Map: ";
		// for (pair<int,int>k : adds) cout << k.first << ": " << k.second << ' ';
		// cout << endl;
		if (i < 0) {
			if (! matrioshka.empty()){
				i2 = matrioshka.top();
				if (i < i2) return false;
				if (adds.find(-i2) == adds.end()) adds[-i2] = -i;
				else adds[-i2] += -i;
			}
			matrioshka.push(i);
		}
		else {
			if (matrioshka.empty()) return false;
			i2 = matrioshka.top();
			if (i2 != -i) return false;
			matrioshka.pop();
			if (adds[i] >= i) return false;
			adds.erase(adds.find(i));
		}
		// cout << "top of stack: " <<matrioshka.top() <<endl;
	}
	if (matrioshka.empty()) return true;
	return false;
}

vector<int> lineToIntSequence(string line) {
	vector<int> ints;
	istringstream iss(line);
	string s;
	while(iss >> s) ints.push_back(stoi(s));
	return ints;
}


int main(){

	string line;
	while (getline(cin, line)) {
		if (isCorrect(lineToIntSequence(line))) cout << ":-) Matrioshka!\n";
		else cout << ":-( Try again.\n";
	}

	return 0;
}
