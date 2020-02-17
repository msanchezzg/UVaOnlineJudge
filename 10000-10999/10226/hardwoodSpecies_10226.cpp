#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){

	map<string, double, less<string>> especies;
	map<string, double>::iterator it;
	int casos, total;
	string esp;

	cin >> casos;
	cin.ignore();
	getline(cin, esp);
	while(casos--){
		//getline(cin, esp);
		especies.clear();
		total = 0;
		while (true){
			getline(cin, esp);
			if(esp == "") break;

			especies[esp] += 1;
			total++;
		}
		
		for(it = especies.begin(); it != especies.end(); it++){
			(*it).second = ((*it).second * 100 ) / total;
			//cout << (*it).first << ' ' << (*it).second << endl;
			printf("%s %.4f\n", (*it).first.c_str(), (*it).second);
		}
		 if(casos != 0) cout << endl;


	}
        


        

	return 0;
}
                    
