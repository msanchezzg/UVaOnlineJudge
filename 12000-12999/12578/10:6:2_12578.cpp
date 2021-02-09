#include <iostream>
#include <cmath>
using namespace std;


int main(){

	double const PI = acos(-1);
	int cases;
	double length, width, radius, circleArea, sqArea;
	cin >> cases;

	while(cases--) {
		cin >> length;
		width = (length*6.0) / 10.0;
		radius = length / 5.0;
		circleArea = PI * radius * radius;
		sqArea = length * width - circleArea;

		printf("%.2lf %.2lf\n", circleArea, sqArea);
	}	

	return 0;
}
