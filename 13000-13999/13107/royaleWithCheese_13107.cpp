#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main(){

	int order, n;
	map<char,int> charsValues;
	string house, id;

	while(getline(cin, house)) {
		order = 1;
		id = "";
		charsValues.clear();

		for(char c : house) {
			n = charsValues[c];
			if (n == 0) {
				n = order;
				charsValues[c] = n;
				order++;
			}
			id += to_string(n);

		}
		replace(id.begin(), id.end(), '2', 'a');
		replace(id.begin(), id.end(), '5', 'b');
		replace(id.begin(), id.end(), '6', 'c');
		replace(id.begin(), id.end(), '9', 'd');
		replace(id.begin(), id.end(), 'a', '5');
		replace(id.begin(), id.end(), 'b', '2');
		replace(id.begin(), id.end(), 'c', '9');
		replace(id.begin(), id.end(), 'd', '6');
		cout << id << '\n';
	}

	return 0;
}
