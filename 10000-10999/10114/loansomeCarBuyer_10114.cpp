#include <iostream>
#include <map>
using namespace std;


double getRate(map<int, double> monthsRates, int month) {
	if (month < 0) return 0.0;
	if (monthsRates.count(month) == 0) return getRate(monthsRates, month-1);
	return monthsRates[month];
}

int main(){

	double payment, loan, rate, car, monthPayment;
	int months, records, m, i;
	map<int, double> monthsRates;

	while(cin >> months >> payment >> loan >> records) {
		if (months < 0) break;
		monthsRates.clear();
		car = loan + payment;
		monthPayment = loan / months;

		while(records--) {
			cin >> m >> rate;
			monthsRates[m] = rate;
		}

		rate = getRate(monthsRates, 0);
		car = car * (1-getRate(monthsRates, rate));
		i = 0;
		if (loan >= car) {
			for(i=1; i<=months; i++) {
				rate = getRate(monthsRates, i);
				car = car * (1-rate);
				loan -= monthPayment;
				if (loan < car) break;
			}
		}

		i == 1 ? cout << i << " month\n" : cout << i << " months\n";
	}

	return 0;
}
