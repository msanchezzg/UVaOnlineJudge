#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;


int main(){
	int nFriends, money, friendsToGive, c;
	bool blank = false;
	string f1, f2;
	unordered_map<string, int> friendsMoney;
	vector<string> friends;
	
	while(cin >> nFriends) {
		if (blank) cout << '\n';
		else blank = true;

		friendsMoney.clear();
		friends.clear();
		for(int i=0; i<nFriends; i++) {
			cin >> f1;
			friends.push_back(f1);
			friendsMoney[f1] = 0;
		}
		
		for(int i=0; i<nFriends; i++) {
			cin >> f1 >> money >> friendsToGive;
			friendsToGive != 0 ? c = money/friendsToGive : c = 0;
			for (int j=0; j<friendsToGive; j++) {
				cin >> f2;
				friendsMoney[f2] += c;
			}
			friendsMoney[f1] -= c*friendsToGive;
		}
		for(string f: friends) {
			cout << f << ' ' << friendsMoney[f] << '\n';
		}
	}

	return 0;
}
