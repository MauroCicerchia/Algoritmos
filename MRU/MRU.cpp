#include <iostream>
using namespace std;

float calcularPosicion(float, float);

int main()
{
	float velocidad, tiempo;
	
	cout << "Ingrese la velocidad del movil: ";
	cin >> velocidad;
	
	cout << "Ingrese el tiempo: ";
	cin >> tiempo;
	
	cout << "La posicion del movil a los " << tiempo << " segundos sera " << calcularPosicion(velocidad, tiempo) << "m";
}

float calcularPosicion(float v, float t)
{
	return v*t;
}
