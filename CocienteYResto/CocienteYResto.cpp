#include <iostream>
using namespace std;

void division(int, int, int&, int&);

int main(){
	int divisor, dividendo, cociente, resto;
	
	cout << "Ingrese el divisor: ";
	cin >> divisor;
	
	cout << "Ingrese el dividendo: ";
	cin >> dividendo;
	
	division(divisor, dividendo, cociente, resto);
	
	cout << "El resultado de " << divisor << "/" << dividendo << " es " << cociente << " y el resto es " << resto;
	
}

void division(int divisor, int dividendo, int &cociente, int &resto)
{
	while(divisor >= dividendo)
	{
		divisor -= dividendo;
		cociente ++;
	}
	
	resto = divisor;
}


