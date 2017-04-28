#include <iostream>
#include <string.h>
using namespace std;

bool promociona(int [], string);

int main()
{
	int notas[4];
	string nombre;
	
	cout << "Ingrese el nombre del alumno: ";
	getline(cin, nombre);
	
	cout << "Ingrese nota del primer parcial: ";
	cin >> notas[0];
	
	cout << "Ingrese nota del primer recuperatorio del primer parcial (0 si no rindio): ";
	cin >> notas[1];
	
	cout << "Ingrese nota del segundo parcial: ";
	cin >> notas[2];
	
	cout << "Ingrese nota del primer recuperatorio del segundo parcial (0 si no rindio): ";
	cin >> notas[3];
	
	if(promociona(notas, nombre))
		cout << "El alumno " << nombre << " promociono la materia.";
	else
		cout << "El alumno " << nombre << " no promociono la materia.";
}

bool promociona(int notas[], string nombre)
{
	if(notas[0] >= 8 && notas[2] >=8)
	{
		return true;
	} else {
		if(notas[0] >= 8)
		{
			if(notas[3] >= 8)
				return true;
			else
				return false;
		} else {
			if(notas[2] >= 8)
			{
				if(notas[1] >= 8)
					return true;
				else
					return false;
			} else {
				return false;
			} 
		}
	}	
}
