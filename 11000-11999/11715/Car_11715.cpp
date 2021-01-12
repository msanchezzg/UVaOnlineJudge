#include <iostream>
#include <math.h>
using namespace std;


/*
 * MRUA Equations:
 * 
 * v = v0 + a*t
 * x = x0 + v0*t + (1/2)*a*t^2
 * v1^2 = v0^2 + 2*a*x
 * 
 */


double getAcceleration(double v0, double v1, double t){
	return (v1 - v0)/t;
}

double getDisplacement(double x0, double a, double t, double v0){
	return x0 + v0*t + (a*t*t)/2;
}

double getTimeFromAcc(double v0, double v1, double a){
	return (v1 - v0)/a;
}

double getFinalVFromDisp(double v0, double a, double x){
	return sqrt(v0*v0 + 2*a*x);
}

double getInitialVFromDisp(double v1, double a, double x){
	return sqrt(v1*v1 - 2*a*x);
}

int main(){

	int i, case_n;
	double u, v, t, a, s, n1, n2;
	i = 0;
	while(cin >> case_n && case_n){
		i += 1;

		switch (case_n) {
		case 1:
			cin >> u >> v >> t;
			a = getAcceleration(u, v, t);
			s = getDisplacement(0, a, t, u);
			n1 = s;
			n2 = a;
			break;
		case 2:
			cin >> u >> v >> a;
			t = getTimeFromAcc(u, v, a);
			s = getDisplacement(0, a, t, u);
			n1 = s;
			n2 = t;
			break;
		case 3:
			cin >> u >> a >> s;
			v = getFinalVFromDisp(u, a, s);
			t = getTimeFromAcc(u, v, a);
			n1 = v;
			n2 = t;
			break;
		case 4:
			cin >> v >> a >> s;
			u = getInitialVFromDisp(v, a, s);
			t = getTimeFromAcc(u, v, a);
			n1 = u;
			n2 = t;
			break;
		}

		printf("Case %d: %.3lf %.3lf\n", i, n1, n2);
	}


	return 0;
}
