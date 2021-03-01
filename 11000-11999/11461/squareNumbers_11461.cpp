#include <iostream>
#include <cmath>
using namespace std;


int main(){

	int n1, n2, sqrt1, sqrt2, res;

	while(cin >> n1 >> n2) {
		if (!n1 && !n2) break;

		sqrt1 = ceil(sqrt(n1));
		sqrt2 = floor(sqrt(n2));
		res = sqrt2 - sqrt1 + 1;
		cout << res << '\n';
	}

	return 0;
}
