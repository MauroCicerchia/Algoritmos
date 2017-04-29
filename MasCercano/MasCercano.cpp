#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int x, cantN, masCercano;
	
	cout << "Ingrese el numero X: ";
	cin >> x;
	
	system("cls");
	
	cout << "Ingrese la cantidad de numeros del conjunto N: ";
	cin >> cantN;
	
	system("cls");
	
	int N[cantN];
	
	for(int i = 0; i < cantN; i++)
	{
		cout << "Ingrese el numero " << i+1 << ":";
		cin >> N[i];
	}
	
	system("cls");
	
	for(int i = 0; i < cantN; i++)
	{
		if(fabs(x - N[i]) < fabs(x - masCercano))	//Modulo
			masCercano = N[i];
	}
	
	cout << "El numero mas cercano es " << masCercano;
}
