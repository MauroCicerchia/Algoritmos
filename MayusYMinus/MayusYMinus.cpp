#include <iostream>
#include <string.h>
using namespace std;

void alternar(string&);

int main()
{
	string frase;
	
	cout << "Ingrese la frase: ";
	getline(cin, frase);
	
	system("cls");
	
	alternar(frase);
	
	cout << frase;
}

void alternar(string &frase)
{
	for(int i = 0; i < frase.length(); i++)
	{
		if(frase[i] >= 'a' && frase[i] <= 'z')
			frase[i] -= 32;
		else	
			if(frase[i] >= 'A' && frase[i] <= 'Z') 
				frase[i] += 32;
	}
}

