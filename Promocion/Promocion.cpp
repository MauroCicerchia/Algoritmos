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
		cout << "hola";
	else
		cout << "chau";
}

bool promociona(int notas[], string nombre)
{
	
}
