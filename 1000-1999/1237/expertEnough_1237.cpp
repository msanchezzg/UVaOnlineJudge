#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Car {
	public:
		string name;
		int maxPrice;
		int minPrice;

		Car(string name, int maxPrice, int minPrice) {
			this->name = name;
			this->maxPrice = maxPrice;
			this->minPrice = minPrice;
		}

		bool inRange(int price) {
			return price >= minPrice && price <= maxPrice;
		}
};


int main(){

	vector<Car> cars;
	int cases, nCars, nQueries, minPrice, maxPrice, p, carsCheck;
	string carName;
	cin >> cases;
	bool newline = false;

	while(cases--) {
		if (newline) cout << "\n";
		else newline = true;

		cars.clear();
		cin >> nCars;

		while(nCars--) {
			cin >> carName >> minPrice >> maxPrice;
			Car c(carName, maxPrice, minPrice);
			cars.push_back(c);
		}

		cin >> nQueries;
		while(nQueries--) {
			cin >> p;
			carsCheck = 0;

			for(Car c : cars) {
				if (c.inRange(p)) {
					carsCheck++;
					if (carsCheck < 2) carName = c.name;
				}
			}
			if (carsCheck != 1) cout << "UNDETERMINED\n";
			else cout << carName << "\n";
		}
	}

	return 0;
}
