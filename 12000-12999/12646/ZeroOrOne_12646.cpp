#include <iostream>
#include <map>
#include <bits/stdc++.h> 
using namespace std;


int main(){

	int a, b, c, count1, count0, index;
	map <int, char> names = {{0, 'A'}, {1, 'B'}, {2, 'C'}};

	while (cin >> a >> b >> c) {
		int arr[] = {a, b, c};
		count1 = count(arr, arr+3, 1);
		count0 = count(arr, arr+3, 0);

		if (count0 == 0 || count1 == 0) cout << "*\n";
		else if (count1 == 1) {
			index = find(arr, arr+3, 1) - arr;
			cout << names[index] << "\n";
		}
		else if (count0 == 1) {
			index = find(arr, arr+3, 0) - arr;
			cout << names[index] << "\n";
		}
	}
	

	return 0;
}
