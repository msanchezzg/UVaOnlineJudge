#include <iostream>
#include <math.h>
using namespace std;


/*
 * FORMULAS USED IN THIS PROBLEM
 * 
 * Cosin theorem:
 * 		a^2 = b^2 + c^2 - 2bc*cos(A)
 * 
 * sin^2(A) + cos^2(A) = 1
 * 
 * Radius of circumscribed circle:
 * 		a/sin(A) = b/sin(B) = c/sin(C) = 2r
 * 
 * Radius of inscribed circle:
 * 		r = sqrt( (s-a)(s-b)(s-c) / s )
 * 		s = (a+b+c)/2
 * 
 * Heron formula:
 * 		Triangle Area = sqrt(s*(s-a)(s-b)(s-c))
 */


double getTriangleSemiperimeter(double a, double b, double c) {
	return (a+b+c) / 2;
}

double getCircleArea(double radius) {
	return M_PI * radius * radius;
}

double getTriangleArea(double a, double b, double c) {
	double s = getTriangleSemiperimeter(a,b,c);
	double area = sqrt(s*(s-a)*(s-b)*(s-c));
	return area;
}

int main(){

	int a, b, c;
	double triangleArea, radius, s, cosA, sinA;
	double inscrCircleArea, circumCircleArea;

	while(cin >> a >> b >> c) {

		// Triangle area
		triangleArea = getTriangleArea(a,b,c); 

		// Inscribed circle
		s = getTriangleSemiperimeter(a,b,c);
		radius = sqrt(
			((s-a)*(s-b)*(s-c)) / s
		);
		circumCircleArea = getCircleArea(radius);

		// Circumscribed circle
		cosA = (b*b + c*c - a*a) / (2.0*b*c);
		sinA = sqrt(1 - cosA*cosA);
		radius = (a/sinA) / 2;
		inscrCircleArea = getCircleArea(radius);

		// Intersections
		inscrCircleArea = inscrCircleArea - triangleArea;
		triangleArea = triangleArea - circumCircleArea;

		printf("%.4lf %.4lf %.4lf\n", inscrCircleArea, triangleArea, circumCircleArea);
	}


	return 0;
}
