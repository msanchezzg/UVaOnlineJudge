#include <iostream>
using namespace std;

int main(){

	float height, distClimb, distSlide, fatigue, distDone, perc;

	while(cin >> height >> distClimb >> distSlide >> fatigue && height) {
		distDone = 0;
		fatigue /= 100;
		perc = distClimb * fatigue;

		for(int day = 1;; day++){

			if (distClimb < 0) distClimb = 0;
			distDone += distClimb;
			if (distDone > height){
				cout << "success on day " << day << '\n';
				break;
			}

			distDone -= distSlide;
			if (distDone < 0){
				cout << "failure on day " << day << '\n';
				break;
			}
			distClimb -= perc;
		}
	}

	return 0;
}
                    
