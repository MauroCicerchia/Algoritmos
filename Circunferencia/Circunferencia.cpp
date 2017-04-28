#include <iostream>
#include <math.h>
using namespace std;

const float pi = 3.141592654;

float calcularArea(float);
float calcularPerimetro(float);

int main()
{
	float radio;
	
	cout << "Ingrese el radio: ";
	cin >> radio;
	
	system("cls");
	
	cout << "El area es " << calcularArea(radio) << " y el perimetro es " << calcularPerimetro(radio);
}

float calcularArea(float r)
{
	return pow(pi*r, 2);
}

float calcularPerimetro(float r)
{
	return 2*pi*r;
}
