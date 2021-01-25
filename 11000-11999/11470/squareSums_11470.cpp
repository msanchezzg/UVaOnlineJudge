#include <iostream>
#include <vector>
using namespace std;


int main(){

	int dimension, a, b, sum, n;
	int c = 0;
	vector<int> squareSums;
	vector<int> matrix;		// Using array arithmetic. matrix2D[i][j] == matrix1D[i*rowLen + j]

	while(cin >> dimension && dimension) {
		squareSums.clear();
		matrix.clear();
		c++;

		for(int i=0; i<dimension*dimension; i++) {
			cin >> n;
			matrix.push_back(n);
		}

		a = 0;
		b = dimension - a - 1;
		while(a <= b){
			sum = 0;
			for(int j=a; j<=b; j++) {
				sum += matrix[a*dimension + j];	// First row
				if (a != b) {
					sum += matrix[b*dimension + j];	// Last row
				}
				if (j != a && j != b) {
					sum += matrix[j*dimension + a];	// First col
					sum += matrix[j*dimension + b];	// Last col
				}

			}
			squareSums.push_back(sum);
			a++; b--;	// Limits of inner square
		}

		printf("Case %d: ", c);
		for(int i=0; i<squareSums.size(); i++) {
			cout << squareSums[i];
			if (i != squareSums.size() - 1) cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}
