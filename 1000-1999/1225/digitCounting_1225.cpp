#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
using namespace std;


void printRes(int array[], int len){
	for(int i=0; i<len-1; i++)
		cout << array[i] << ' ';

	cout << array[len-1] << endl;
}

void countDigits(int array[], int n){
	string s = to_string(n);
	for(int i=0; i<=9; i++)
		array[i] += count(s.begin(), s.end(), i+48);
}

void funcion(int array[], int n){
	if(n!=0){
		countDigits(array, n);
		funcion(array, n-1);
	}
}

int main(){

	int casos, in;
	int digits[10];
	cin >> casos;

	while(casos--){
		cin >> in;
		memset(digits, 0, sizeof(digits));
		funcion(digits, in);
		printRes(digits, 10);
	}
        
	return 0;
}
                    
