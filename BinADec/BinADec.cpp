#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool esBinario(string);

int toDec(string);

int main()
{
	string num;
	
	cin >> num;
		
	if(!esBinario(num))
		cout << "No ha ingresado un numero binario." << endl;
	else
		cout << "El numero en decimal es " << toDec(num) << endl;
	
}

//Determina si la cadena ingresada es Binaria o no
bool esBinario(string num)
{
	for(int i = 0; i < num.length(); i++){
		if(num.at(i) != '1' && num.at(i) != '0'){
			return false;
		}
	}
	return true;
}

//Convierte el numero a decimal
int toDec(string num)
{
	int result = 0;
	
	//Recorre el string desde el ultimo caracter hasta el primero
	for(int i = 0, j = num.length() - 1; j >= 0; i++, j--)
	{
		if(num.at(j) == '1')
			result += pow(2, i);
	}
	
	return result;
}
