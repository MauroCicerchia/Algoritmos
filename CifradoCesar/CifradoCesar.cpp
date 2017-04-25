#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

string cifrar(int key, string frase)
{
	for(int i = 0; i < frase.length(); i++)
	{
		if(frase[i] >= 'a' && frase[i] <= 'z')
		{
			if(frase[i] + key > 'z')
				frase[i] = frase[i] + key - 26;
			else
				frase[i] = frase[i] + key;
				
		} else if(frase[i] >= 'A' && frase[i] <= 'Z')
			if(frase[i] + key > 'Z')
					frase[i] = frase[i] + key - 26;
				else
					frase[i] = frase[i] + key;
	}
	
	return frase;
}

int main()
{
	string frase;
	int key;
	
	cout << "Ingrese la frase que desea cifrar: ";
	getline(cin, frase);
	
	do
	{
	system("cls");
	cout << "Ingrese la clave de cifrado (1-25): ";
	cin >> key;
	}while(key <= 1 && key >= 25);
	
	system("cls");
	
	cout << "Frase cifrada: " << cifrar(key, frase);
	
	return 0;
}
