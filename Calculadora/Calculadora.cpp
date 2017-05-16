#include <iostream>
#include <string>
#include <windows.h>
#include <math.h>
using namespace std;

bool esOperando(char);
bool esOperador(char);
int stoi(string);
void sacarEspacios(string&);
bool esCorrecta(string);
int separarTerminos(string, string[], string[]);
int calcularTerminos(string[], string[], int[], string[], int&);
int operar(string);

int main()
{
	string cadena;
	int n;
	
	getline(cin, cadena);
	sacarEspacios(cadena);
	
	if(esCorrecta(cadena))
	{
		system("cls");
		cout << cadena << "=" << operar(cadena) << endl;
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

//Convierte una cadena de caracteres numericos a int.
int stoi(string s)
{
	return atoi(&s.at(0));;
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

//Separa la cadena en dos vectores, uno para operadores y otro para operaciones. Devuelve la cantidad de terminos.
int separarTerminos(string cadena, string operandos[], string operaciones[])
{	
	int n = 0;

	for(int i = 0; i < cadena.length(); i++)			//Recorre toda la cadena.
	{
		if(isdigit(cadena.at(i)))						//Si es un numero...
		{
			operandos[n] += cadena.at(i);				//Lo guarda en el vector de operandos.
		} else {
			operaciones[n] = cadena.at(i);				//Si no, lo guarda en el vector de operaciones.
			n++;
		}
	}
	
	return n;
}

//Resuelve multiplicaciones y divisiones. Luego sumas y restas.
int calcularTerminos(string operandos[], string operaciones[], int nOperandos[], string nOperaciones[], int &n)
{
	int o = 0, result = 0;
	
	nOperandos[0] = stoi(operandos[0]);									//Guarda el primer caracter en el vector de operandos numericos
	for(int i = 0; i < n; i++)											//Recorre ambos vectores
	{
		if(operaciones[i] == "+" || operaciones[i] == "-")				//Si la operacion actual es una suma o una resta...
		{
			nOperaciones[o] = operaciones[i];							//...guarda la operacion y el caracter siguiente en los vectores correspondientes.
			o++;
			nOperandos[o] = stoi(operandos[i+1]);									
			
		} else if(operaciones[i] == "*") {								//Si es una multiplicacion o division realiza la operacion y guarda el resultado en el vector de numeros.
			nOperandos[o] = nOperandos[o] * stoi(operandos[i+1]);					
		} else if(operaciones[i] == "/") {
			nOperandos[o] = nOperandos[o] / stoi(operandos[i+1]);
		}
	}

	result += nOperandos[0];											//Suma el primer numero al resultado
	for(int i = 0; i < o; i++)											//Recorre ambos vectores
	{
		if(nOperaciones[i] == "+")										//Realiza la suma o resta y suma el resultado a la variable.
			result += nOperandos[i+1];
		else if(nOperaciones[i] == "-")
			result -= nOperandos[i+1];
	}
	
	return result;
}

//Calcula el resultado.
int operar(string cadena)
{
	string operandos[9], operaciones[8], nOperaciones[8], aux1;
	int nOperandos[9], n, result;

	n = separarTerminos(cadena, operandos, operaciones);
	
	return calcularTerminos(operandos, operaciones, nOperandos, nOperaciones, n);

}

