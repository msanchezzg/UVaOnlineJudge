#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


template<typename T>
set<T> uniqueIn1Set(set<T> &s1, set<T> &s2, set<T> &s3) {
	// s1 - s2 - s3
	set<T> s, ss;
	set_difference((s1).begin(), (s1).end(), (s2).begin(), (s2).end(), inserter(s, s.begin()));
	set_difference(s.begin(), s.end(), (s3).begin(), (s3).end(), inserter(ss, ss.begin()));
	return ss;
}

template<typename T>
set<T> uncommonIn1Set(set<T> &s1, set<T> &s2, set<T> &s3) {
	// (s2 & s3) - s1;
	set<T> s, ss;
	set_intersection((s3).begin(), (s3).end(), (s2).begin(), (s2).end(), inserter(s, s.begin()));
	set_difference(s.begin(), s.end(), (s1).begin(), (s1).end(), inserter(ss, ss.begin()));
	return ss;
}


int main(){

	int cases, r, l, s, ch;
	set<int> leju, rony, sujon, unique, uncommon;

	cin >> cases;
	for(int c=1; c<=cases; c++) {
		leju.clear();
		rony.clear();
		sujon.clear();

		cin >> l >> r >> s;
		for (int i = 0; i < l; i++) {
			cin >> ch;
			leju.insert(ch);
		}
		for (int i = 0; i < r; i++) {
			cin >> ch;
			rony.insert(ch);
		}
		for (int i = 0; i < s; i++) {
			cin >> ch;
			sujon.insert(ch);
		}

		printf("Case #%d:\n", c);

		// Leju
		unique = uniqueIn1Set(leju, rony, sujon);
		uncommon = uncommonIn1Set(leju, rony, sujon);
		cout << unique.size() << ' ' << uncommon.size() << '\n';

		// Rony 
		unique = uniqueIn1Set(rony, sujon, leju);
		uncommon = uncommonIn1Set(rony, sujon, leju);
		cout << unique.size() << ' ' << uncommon.size() << '\n';

		// Sujon
		unique = uniqueIn1Set(sujon, leju, rony);
		uncommon = uncommonIn1Set(sujon, leju, rony);
		cout << unique.size() << ' ' << uncommon.size() << '\n';
	}

	return 0;
}