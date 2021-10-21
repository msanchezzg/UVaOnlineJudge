#include <iostream>
using namespace std;



bool isTriangle(long a, long b, long c) {
	if (a <= 0 || b <= 0 || c <= 0) return false;
	if (a+b <= c) return false;
	if (a+c <= b) return false;
	if (b+c <= a) return false;
	return true;
}

bool isEquilateral(long a, long b, long c) {
	if (a == b && b == c) return true;
	return false;
}

bool isIsosceles(long a, long b, long c) {
	if (a == b || a == c || b == c) return true;
	return false;
}

int main(){

	int cases;
	long a, b, c;
	cin >> cases;

	for (int i=1; i<=cases; i++) {
		cin >> a >> b >> c;

		if (! isTriangle(a, b, c)) printf("Case %d: Invalid\n", i);
		else if (isEquilateral(a, b, c)) printf("Case %d: Equilateral\n", i);
		else if (isIsosceles(a, b, c)) printf("Case %d: Isosceles\n", i);
		else printf("Case %d: Scalene\n", i);
	}

	return 0;
}
