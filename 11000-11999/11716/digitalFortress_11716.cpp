#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main(){

	int cases, len;
	double rowLen;
	string line, decrypted;
	cin >> cases;
	cin.ignore();

	while(cases--) {
		getline(cin, line);
		decrypted = "";
		rowLen = sqrt(line.length());
		if (rowLen - floor(rowLen) != 0) {	// Number is not perfect square
			cout << "INVALID\n";
			continue;
		}
		len = int(rowLen);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				decrypted += line[len*j + i];
			}
		}
		cout << decrypted << '\n';
		
	}

	return 0;
}
