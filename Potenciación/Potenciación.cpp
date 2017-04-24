#include <iostream>
using namespace std;

int potencia(int num, int exp)
{
	long int resultado = num;
	
	for(int i = 0; i < exp - 1; i++)
		resultado = resultado*num;
		
	return resultado;
}

int main()
{
	int num, exp;
	
	cout << "Ingrese el numero: ";
	cin >> num;
	
	cout << "Ingrese el exponente: ";
	cin >> exp;
	
	long int resultado = potencia(num, exp);
	
	cout << "El resultado es: " << resultado;
}
