#include <iostream>
using namespace std;

char determinarLetra(int);

int main()
{
	int num;
	
	do
	{
		cout << "Ingrese un numero entre el 1 y el 26 para saber su letra: ";
		cin >> num;
		
		system("cls");
		
		if(num < 1 || num > 26)
			cout << "Numero invalido." << endl;
	}while(num < 1 || num > 26);
	
	system("cls");
	cout << "La letra correspondiente al numero " << num << " es la '" << determinarLetra(num) << "'";
}

char determinarLetra(int num)
{
	char letra;
	
	letra = 'a' + num - 1;
	
	return letra;
}
