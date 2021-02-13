#include <iostream>
#include <string>
using namespace std;


int main(){

	int i, len;
	string line;

	while(getline(cin, line) && line[0] != 'E') {
		len = line.length();
		if (len == 1) {
			if (line[0] == '1') i = 1;
			else i = 2;
		}
		else if (len < 10) i = 3;
		else i = 4;

		cout << i << '\n';
	}

	return 0;
}
