#include <iostream>
#include <math.h>
using namespace std;


int main(){

	int lines, pastes, i;

	i = 0;
	while(cin >> lines and lines > 0) {
		i++;
		pastes = int(ceil(log2(lines)));
		printf("Case %d: %d\n", i, pastes);
	}

	return 0;
}
