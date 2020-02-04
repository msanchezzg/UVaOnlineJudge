#include <iostream>
#include <string>
using namespace std;

int main(){

	string texto, s;
	bool primero = true;

	while(getline(cin, s)){
		texto = "";

		for(int i=0; i<s.length(); i++){
			if (s[i] == '\"'){
				if (primero){
					texto += "``";
					primero = false;
				}
				else{
					texto += "\'\'";
					primero = true;
				}
			}
			
			else texto += s[i];
		}
		cout<<texto<<'\n';
	}

	return 0;
}
                    
