#include <iostream>
using namespace std;


/**
 * 1:	1							(1º)
 * 3:	3	5	7					(2º)
 * 5:	9	11	13	15	17			(3º)
 * 7:	19	21	23	25	27	29	31	(4º)
 * 
 * 3:	7	= 2*n + 1
 * 5:	17	= 3*n + 2
 * 7:	31 	= 4*n + 3
 * 9:	49	= 5*n + 4
 * 
 * odd:	last = oddOrder*odd + (oddOrder-1)
 * 
 */

long getLastLineOdd(int odd) {
	long oddOrder = (odd + 1) / 2;
	long lastOdd = oddOrder * (odd + 1) - 1;
	return lastOdd;
}

long getNLastOddsSum(int odd, int n) {
	long lastOdd = getLastLineOdd(odd);
	/*
	 * Sum of n previous odd numbers
	 * 	lastOdd + (lastOdd - 2) + (lastOdd - 4) + ... = 
	 * 	= n*lastOdd - (n-1)*n 
	 */
	return n*lastOdd - (n-1)*n;
}


int main(){

	int odd;
	
	while(cin >> odd) {
		cout << getNLastOddsSum(odd, 3) << '\n';
	}

	return 0;
}
