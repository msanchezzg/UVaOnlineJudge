#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


int main(){

	int frosh, c, popularComb, popularCombStudents, ncourses = 5;
	map<set<int>,int> coursesCombinationsCounter;

	while(cin >> frosh && frosh) {
		coursesCombinationsCounter.clear();
		popularComb = 0;

		for(int f=0; f<frosh; f++) {
			set<int> courses;
			for(int i=0; i<ncourses; i++) {
				cin >> c;
				courses.insert(c);
			}
			if (coursesCombinationsCounter.find(courses) != coursesCombinationsCounter.end())
				coursesCombinationsCounter[courses]++;
			else
				coursesCombinationsCounter[courses] = 1;

			if (coursesCombinationsCounter[courses] > popularComb) popularComb = coursesCombinationsCounter[courses];
		}

		popularCombStudents = 0;
		for(auto const &c : coursesCombinationsCounter) {
			if (c.second == popularComb) popularCombStudents += popularComb;
		}

		cout << popularCombStudents << '\n';
	}


	return 0;
}
