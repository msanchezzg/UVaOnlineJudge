#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main(){

	int fredCourses, categories, catCourses, catMinCourses, coursesCont, c;
	set<int> fredCoursesIDs;
	bool reqsOK, catOK;

	while(cin >> fredCourses && fredCourses){
		cin >> categories;
		fredCoursesIDs.clear();
		reqsOK = true;

		for(int i=0; i<fredCourses; i++) {
			cin >> c;
			fredCoursesIDs.insert(c);
		}
		for(int i=0; i<categories; i++) {
			cin >> catCourses >> catMinCourses;
			coursesCont = 0;
			for(int j=0; j<catCourses; j++) {
				cin >> c;
				if (fredCoursesIDs.find(c) != fredCoursesIDs.end()) coursesCont++;
			}
			catOK = (coursesCont >= catMinCourses);
			reqsOK &= catOK;
		}

		reqsOK ? cout << "yes\n" : cout << "no\n";
	}

	return 0;
}
