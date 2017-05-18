#include <iostream>
#include <string>
using namespace std;

int contar(string);

int main() {
	string texto;
	
	cout << "Ingrese una palabra o frase: ";
	getline(cin, texto);
	
	cout << "La cantidad de caracteres: " << contar(texto);
}

//Cuenta las letras de una cadena
int contar(string texto) {
	int cont;
	for(int i = 0; i < texto.length(); i++) {
		if(isalpha(texto[i])) {
			cont++;
		}
	}
	return cont;
}
