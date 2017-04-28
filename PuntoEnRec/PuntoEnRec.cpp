#include <iostream>
using namespace std;

bool estaEnRectangulo(float[], float[]);

int main()
{
	float rectangulo[4], punto[2];
	
	cout << "Ingrese la coordenada x del punto: ";
	cin >> punto[0];
	
	cout << "Ingrese la coordenada y del punto: ";
	cin >> punto[1];
	
	for(int i = 0; i < 4; i++)
	{
		cout << "Ingrese el vertice " << i+1 << ": ";
		cin >> rectangulo[i];
	}
	
	system("cls");
	
	if(estaEnRectangulo(punto, rectangulo))
	{
		cout << "El punto esta dentro del rectangulo.";
	} else {
		cout << "El punto no esta dentro del rectangulo.";
	}
}

bool estaEnRectangulo(float punto[], float rectangulo[])
{
	return punto[0] >= rectangulo[0] && punto[0] <= rectangulo[2] && punto[1] >= rectangulo[1] && punto[1] <= rectangulo[3];
}
