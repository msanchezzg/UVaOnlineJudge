#include <iostream>
#include <vector>
using namespace std;


int main(){

	int set, nstacks, n, total, nmoves, meanHeight;
	set = 0;
	vector<int> stacks;

	while (cin >> nstacks && nstacks) {
		set++;
		total = 0;
		nmoves = 0;
		stacks.clear();

		for (int i = 0; i < nstacks; i++) {
			cin >> n;
			stacks.push_back(n);
			total += n;
		}

		meanHeight = total / nstacks;

		for (int s : stacks) {
			if (s > meanHeight) nmoves += (s - meanHeight);
		}

		printf("Set #%d\nThe minimum number of moves is %d.\n\n", set, nmoves);
		
		
	}



	return 0;
}
