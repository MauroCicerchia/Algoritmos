#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int num, par = 0, impar = 0;
	
	do
	{
		cout << "Ingrese un numero: ";
		cin >> num;
		
		system("cls");	
	
		if(num > 0)
			if(num % 2 == 0)
				par++;
			else
				impar++;
		
		if(num < 0)
			cout << "Solo se aceptan numeros positivos." << endl;
			
	}while(num != 0);
	
	cout << "Cantidad de pares: " << par << endl;
	cout << "Cantidad de impares: " << impar << endl;
	
	return 0;
}
