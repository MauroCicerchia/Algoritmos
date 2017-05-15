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
int operar(int, string, string);

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

//Funcion que calcula los terminos de la cadena
void calcularTerminos(string &cadena)
{

	string terminos[9], operaciones[8], aux1;
	int n = 0;
	
	for(int i = 0; i < cadena.length(); i++)			//Recorre todos los caracteres de la cadena.
	{
		if(cadena.at(i) != '+' && cadena.at(i) != '-')	//Si el caracter actual no es un separador de terminos, lo agrega a una cadena auxiliar.
		{
			aux1 += cadena.at(i);
		}
		if(i != cadena.length() - 1)	//Si el caracter actual no es el ultimo...
		{
			if(cadena.at(i+1) == '+' || cadena.at(i+1) == '-')	//Si el caracter siguiente es un separador de terminos...
			{
				terminos[n] = aux1;								//...agrega la cadena auxiliar al vector de terminos y agrega el separador de terminos al vector de operadores.
				operaciones[n] = cadena.at(i+1);
				n++;
				aux1.clear();
			}
		} else {									//Si es el ultimo...
			terminos[n] = aux1;						//...agrega la cadena auxiliar al vector de terminos
			n++;
			aux1.clear();
		}
	}
	
	//Ahora todos los terminos estan separados.
	
	//3/5*6
	for(int i = 0; i < n; i++)
	{
		//cout << terminos[i] << endl;
		//TODO resolver terminos
		//aux1, operacao, aux2, resuelvo, recursivo.
		bool primero = true;
		int total = 0;
		string aux;
		string operacion;
		
		for(int j = 0; j < terminos[n].length(); j++)
		{
			if(terminos[n].at(i) != '*' && terminos[n].at(i) != '/')	//Si el caracter actual es un numero
			{

					aux += terminos[n].at(i);
				
			} else {													//Si es un * o /
				
				if(primero)
				{
					total += stoi(aux);	//Guarda el valor numerico de aux
					primero = false;
				} else {
					total = operar(total, operacion, aux);
				}
					
				operacion = terminos[n].at(i);
				
			}
		}
		
		terminos[n] = itos(total);
	}
	
	for(int i = 0; i < operaciones.length(); i++)
		cout << terminos[i] << operaciones[i];
	cout << terminos[terminos.length()-1];
}

//Realiza las multiplicaciones y divisiones
int operar(int total, string operacion, string aux)
{
	if(operacion == "*")
		total *= aux;
	else
		total /= aux;
	
	return total;
}

//Calcula el resultado de los terminos
float resultado(string cadena)
{
	float result = 0;
	
	return result;
}
