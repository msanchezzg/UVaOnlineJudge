#include <iostream>
using namespace std;


int f91 (int n){
	if(n<=100) return f91(f91(n+11));
	else 	   return n-10;
}


int main(){

	int a, b;
	while(cin>>a && a){
		if(a<101) b = 91;
		else b = a-10;
		//b=f91(a);
		cout<<"f91("<<a<<") = "<<b<<endl;
	}
	return 0;
}
                    
