#include <iostream>
using namespace std;

double sqrt(double);

int main() {
	double n;
	
	cin >> n;
	cout << "Raiz cuadrada de " << n << " = " << sqrt(n);
}

double sqrt(double x) {
	double n1 = 0, n2 = 1, n;
	
	while(!(x >= n1*n1 && x < n2*n2)) {
		n1++; 
		n2++;
	}
	
	if(n1*n1 == x)
		return n1;
		
	for(int i = 0; i < 25; i++) {
		n = (n1+n2)/2;
		if(n*n == x) {
			return n;
		} else if(n*n < x) {
			n1 = n;
		} else {
			n2 = n;
		}
	}
	
	return n;
}
