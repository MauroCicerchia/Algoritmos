#include <iostream>
using namespace std;

void cuentas(float, float);

int main()
{
	float a, b;
	
	cout << "Ingrese un numero: ";
	cin >> a;
	cout << "Ingrese otro numero: ";
	cin >> b;
	
	cuentas(a, b);
	
}

void cuentas(float a, float b)
{
	cout << "Suma: " << a + b << endl;
	cout << "Multiplicacion: " << a * b << endl;
	cout << "Resta: " << a - b << endl;
}
