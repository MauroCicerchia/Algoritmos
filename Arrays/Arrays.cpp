#include <iostream>
using namespace std;

int main() {
	int n, num;
	
	do {
		cout << "Ingrese un numero entre 1 y 20: ";
		cin >> n;
	}while(n <= 0 || n > 20);
	
	int vector[n];
	
	for(int i = 0; i < n; i++) {
		vector[i] = (i+1)*2;
	}
	
	do {
		cout << "Ingrese un numero para para buscar:";
		cin >> num;
	}while(num % 2 != 0);
	
	for(int i = 0; i < n; i++) {
		if(vector[i] == num)
			cout << "Encontrado en posicion " << i;
	}
	
	
	
}
