#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

bool esOperando(char);
bool esOperador(char);
void sacarEspacios(string&);
bool esCorrecta(string);
void calcularTerminos(string&);
float resultado(string);

int main()
{
	string cadena;
	
	getline(cin, cadena);
	sacarEspacios(cadena);
	
	if(esCorrecta(cadena))
	{
		/*system("cls");
		cout << cadena <<  "=" << resultado(cadena) << endl;*/
		calcularTerminos(cadena);
		return 1;
	} else { 
		return 0;
	}
}

//Funcion que devuelve true si el caracter es un numero.
bool esOperando(char caracter)
{
	if(caracter >= '0' && caracter <= '9')
	{	
		return true;
	}
	return false;
}

//Funcion que devuelve true si el caracter es un operador.
bool esOperador(char caracter)
{
	if(caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/')
		return true;
	else
		return false;
}

//Funcion para eliminar los espacios de la cadena.
void sacarEspacios(string &cadena)
{
	for(int i = 0; i < cadena.length(); i++)
		if(cadena.at(i) == ' ')
		{
			cadena.erase(i, 1);
			i--;
		}
}

//Funcion que determina si la cadena es correcta o no.
bool esCorrecta(string cadena)
{
	int cantOperadores = 0, cantOperandos = 0;
	bool antEsOperador = true;
	
	for(int i = 0; i < cadena.length(); i++)
	{

		if(esOperando(cadena.at(i)))			//Si el caracter actual es un operando...
		{	
			if(antEsOperador){					//...y el caracter anterior era un operador, aumenta la cantidad de operandos y resetea cantOperadores.
				cantOperandos++;
				cantOperadores = 0;
				antEsOperador = false;
			}
			
			if(cantOperandos > 9)				//...y la suma de operandos excede 9, devuelve un error.
			{
				system("cls");
				cout << "Syntax Error. Se han ingresado mas de nueve operandos.";
				return false;
			}
			
		} else if(esOperador(cadena.at(i))) {	//Si el caracter actual es un operador...
			
			antEsOperador = true;
			cantOperadores++;
			
			if(cantOperadores > 1)				//...y hay mas de 1 caracter seguido, devuelve un error.
			{
				system("cls");
				cout << "Syntax Error. Se han ingresado dos operadores seguidos.";
				return false;
			}
			
			if(i == 0 || i == cadena.length() - 1)	//...y es la primera o la ultima posicion, devuelve un error.
			{
				system("cls");
				cout << "Syntax Error. No se puede empezar o terminar con un operador.";
				return false;
			}
			
		} else {								//Si el caracter actual no es ni un operando ni un operador, devuelve un error.
			system("cls");
			cout << "Syntax Error. Se ha ingresado un caracter invalido";
			return false;
		}
	}
	return true;
}

void calcularTerminos(string &cadena)
{
	//"1+2*3+4/2+5"
	string terminos[9], aux1 = NULL, aux2 = NULL;
	int n;
	
	for(int i = 0, n = 0; i < 17; i++)			//Recorre todos los caracteres posibles de la cadena.
	{
		if(cadena.at(i) != '+' && cadena.at(i) != '-')	//Si el caracter actual no es un separador de terminos, lo agrega a una cadena auxiliar.
		{
			aux1 += cadena.at(i);
		}
		if(cadena.at(i+1) == '+' || cadena.at(i) == '-')
		{
			terminos[n] = aux1;
			n++;
			aux1.erase(0,aux1.length());
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << terminos[n] << endl;
	}
}

//Calcula el resultado de la operación
float resultado(string cadena)
{
	float result = 0;
	
	return result;
}
