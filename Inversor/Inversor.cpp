#include <iostream>
#include <string>
using namespace std;

void invertir(string);

int main()
{
	string frase;
	
	cout << "Frase: ";
	
	//Para leer la frase con espacios
	getline(cin, frase);
	
	invertir(frase);	
}

void invertir(string frase)
{
	//Recorre el string desde el ultimo caracter hasta el primero
	for(int i = frase.length() - 1; i >= 0; i--)
	{
		cout << frase.at(i);
	}
}
