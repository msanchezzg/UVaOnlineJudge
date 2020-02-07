#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(){
	set<int> sjack, sjill;
	vector<int> intersect;
	int jack, jill, n;
	set<int>::iterator it;

	while(1){
		cin >> jack >> jill;

		if (!jack && !jill) break;

		intersect.clear();
		sjack.clear();
		sjill.clear();
		
		while(jack--) {
			cin >> n;
			sjack.insert(n);
		}
		while(jill--) {
			cin >> n;
			sjill.insert(n);
		}

		set_intersection(sjack.begin(), sjack.end(),
			sjill.begin(), sjill.end(), inserter(intersect, intersect.begin()));
		
		cout << intersect.size() << endl;
	}

	return 0;
}
                    
