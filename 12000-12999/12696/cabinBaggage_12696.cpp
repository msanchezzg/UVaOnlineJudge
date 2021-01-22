#include <iostream>
using namespace std;


bool checkSumOfBaggageDims(double length, double width, double depth) {
	double maxSum = 125;	// In cm
	if ((length + width + depth) > maxSum) return false;
	return true;
}

bool isBaggageValid(double length, double width, double depth, double weight) {
	// In cm
	double maxLength = 56;	
	double maxWidth = 45;
	double maxDepth = 25;
	// In kg
	double maxWeight = 7.0;

	if (weight > maxWeight) return false;
	if (length > maxLength) return checkSumOfBaggageDims(length, width, depth);
	if (width > maxWidth) return checkSumOfBaggageDims(length, width, depth);
	if (depth > maxDepth) return checkSumOfBaggageDims(length, width, depth);

	return true;
}


int main(){

	int cases;
	int totalOK = 0;
	double length, width, depth, weight;
	cin >> cases;

	while(cases--) {
		cin >> length >> width >> depth >> weight;

		if (isBaggageValid(length, width, depth, weight)) {
			cout << "1\n";
			totalOK++;
		}
		else cout << "0\n";
	}

	cout << totalOK << '\n';

	return 0;
}
