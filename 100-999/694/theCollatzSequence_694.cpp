#include <iostream>
using namespace std;


int collatz(int a, int limit) {
	int terms = 1;
	long x = a;

	while(true) {
		if (x == 1) { break; }

		if (x % 2 == 0) { x /= 2; }
		else { x = 3*x +1; }

		if (x > limit) { break; }

		terms++;
	}
	return terms;
}

int main(){

	int c, a, limit, terms;
	c = 0;

	while (cin >> a >> limit && a>0 && limit>0) {
		c++;
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n",
			c, a, limit, collatz(a, limit));
	}

	return 0;
}
