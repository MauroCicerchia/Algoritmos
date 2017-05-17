#include <iostream>
using namespace std;

int raiz(int);

int main() {
	int n;
	
	do {
		cin >> n;
	} while(n < 1);
	
	cout << "raiz cuadrada de " << n << " = " << raiz(n); 
}

int raiz(int x) {
	int n = 1;
	while(n*n <= x) {
		n++;
	}
	
	return n-1;
}
