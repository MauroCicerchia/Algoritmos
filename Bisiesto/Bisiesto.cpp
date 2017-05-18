#include <iostream>
#include <string>
using namespace std;

bool esBisiesto(int);

int main() {
	
	int a;
	cout << "Ingrese el año: ";
	cin >> a;
	if(esBisiesto(a))
		cout << "Es bisiesto";
	else
		cout << "No es bisiesto";
}

bool esBisiesto(int a) {
	if(a % 4 == 0 && !(a % 100 == 0 && a % 400 != 0))
		return true;
	else
		return false;
}
