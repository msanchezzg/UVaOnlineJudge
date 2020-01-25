#include <iostream>
#include <cmath>
using namespace std;


int getNDivisores(long n){
    long div = 0;
    for(long i=1; i<sqrt(n)+1; i++){
        if(n%i == 0) div++;
    }
    return div*2;
}


int main() {

    long n, ndiv, s;
    while(cin>> n && n != 0){
        /*
        ndiv = getNDivisores(n);
        if (ndiv%2 == 0) cout<<"no\n";
        else cout<<"yes\n";
        */
       s = long(sqrt(n));
       if (s*s == n) cout<<"yes\n";
       else cout<<"no\n";
    }

    return 0;
}