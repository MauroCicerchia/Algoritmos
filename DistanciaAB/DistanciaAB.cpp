#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

void calcularDistancia(float, float, float, float, float&);

int main()
{
	float x1, x2, y1, y2, distancia;
	
	cout << "Ingrese la posicion x1: ";
	cin >> x1;
	
	cout << "Ingrese la posicion y1: ";
	cin >> y1;
	
	cout << "Ingrese la posicion x2: ";
	cin >> x2;
	
	cout << "Ingrese la posicion y2: ";
	cin >> y2;
	
	calcularDistancia(x1, y1, x2, y2, distancia);
	
	system("cls");
	
	cout << "La distancia entre puntos es " << distancia << "." << endl;
}

void calcularDistancia(float x1, float y1, float x2, float y2, float &distancia)
{	
	//Calcula la distancia con el teorema de pitagoras
	distancia = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}


