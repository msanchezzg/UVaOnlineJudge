#include <iostream>
using namespace std;


int main(){

	int props, hunters, objects, possibleFailures;

	while (cin >> props >> hunters >> objects) {
		if (objects == props) cout << "Hunters win!\n";
		else {	// objects > props
			possibleFailures = objects - props;
			if ((hunters - possibleFailures) > 0) cout << "Hunters win!\n";
			else cout << "Props win!\n";
		}
	}
	

	return 0;
}
