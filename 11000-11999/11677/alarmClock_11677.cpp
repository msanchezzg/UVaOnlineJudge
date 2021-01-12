#include <iostream>
using namespace std;


int main(){

	int h1, m1, h2, m2, time1, time2, diff;

	while(cin >> h1 >> m1 >> h2 >> m2) {
		if (!h1 && !h2 && !m1 && !m2) break;

		if (h2 < h1) h2 += 24;
		else if (h2 == h1 && m2 <= m1) h2 += 24;

		time1 = h1*60 + m1;
		time2 = h2*60 + m2;
		cout << time2 - time1 << '\n';
	}

	return 0;
}
