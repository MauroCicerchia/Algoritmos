#include <iostream>
#include <windows.h>
using namespace std;

void fibo(int max)
{
	int anterior = 0, actual = 1, aux;
	
	cout << 0 << " ";
	
	for(int i = 0; i < max; i++)
	{
		cout << actual << " ";
		aux = actual;
		actual += anterior;
		anterior = aux;
	}
}

int main()
{
	int max;
	
	do
	{
		cout << "Ingrese la cantidad de cifras que desea mostrar: ";
		cin >> max;
		
		system("cls");
		
		if(max <= 0)
			cout << "La cantidad debe ser un numero mayor a 0." << endl;
			
	}while(max <= 0);
	
	fibo(max);
}
