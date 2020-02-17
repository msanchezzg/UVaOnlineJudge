#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){

	map<char, char> soundex;
	soundex['B'] = soundex['F'] = soundex['P'] = soundex['V'] = '1';
	soundex['C'] = soundex['G'] = soundex['J'] = soundex['K'] = soundex['Q']
		= soundex['S'] = soundex['X'] = soundex['Z'] = '2';
	soundex['D'] = soundex['T'] = '3';
	soundex['L'] = '4';
	soundex['M'] = soundex['N'] = '5';
	soundex['R'] = '6';

	string s, res;
	char anterior, numAnterior, num;

	while(getline(cin, s)){
		res.clear();
		anterior = numAnterior = 'd';
		for(char c: s){
			if(c == anterior) continue;
			num = soundex[c];
			if(numAnterior == num) continue;
			if(isdigit(num)) res += num;
			anterior = c;
			numAnterior = num;
		}
		cout << res << endl;
	}

	return 0;
}
                    
