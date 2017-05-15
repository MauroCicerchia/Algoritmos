#include <iostream>
#include <string>
using namespace std;

void format(string&);
bool esPalindromo(string);

int main() {
	string frase;
	getline(cin, frase);
	format(frase);
	if(esPalindromo(frase))
		cout << "Es palindromo.";
	else
		cout << "No es palindromo.";
}

//Funcion para eliminar los espacios de la cadena y dejar todos los caracteres en minuscula.
void format(string &cadena) {
	for(int i = 0; i < cadena.length(); i++){
		if(cadena.at(i) >= 'A' && cadena.at(i) <='Z') {
			cadena.at(i) = tolower(cadena.at(i));
		}
		if(cadena.at(i) == ' ')
		{
			cadena.erase(i, 1);
			i--;
		}
	}
}

bool esPalindromo(string frase) {
	for(int i = 0, j = frase.length() - 1; i <= j; i++, j--) {
		if(frase.at(i) != frase.at(j))
			return false;
	}
	return true;
}
