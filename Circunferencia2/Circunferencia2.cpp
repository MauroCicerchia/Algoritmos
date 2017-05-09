#include <iostream>
#include <math.h>
using namespace std;

const float pi = 3.141592654;

float calcularLongitud(float);

int main()
{
	float radio;
	
	cout << "Ingrese el radio: ";
	cin >> radio;
	
	system("cls");
	
	cout << "La longitud es " << calcularLongitud(radio);
}

float calcularLongitud(float r)
{
	return 2*pi*r;
}
