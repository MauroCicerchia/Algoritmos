#include <iostream>
#include <stdlib.h>
#include "estenl.h"
using namespace std;

int const camino[9][9] =	{	 /*C0 C1 C2 C3 C4 C5 C6 C7 C8*/
							/*C0*/{ 0,10, 7, 0, 0, 0, 0, 0, 0},
							/*C1*/{10, 0, 6, 6, 0, 0, 0, 0, 0},
							/*C2*/{ 7, 6, 0,12, 9, 0, 0, 0, 0},
							/*C3*/{ 0, 6,12, 0,15, 8, 0, 0, 0},
							/*C4*/{ 0, 0, 9,15, 0,13, 0, 0, 0},
							/*C5*/{ 0, 0, 0, 8,13, 0,13,15, 0},
							/*C6*/{ 0, 0, 0, 0, 0,13, 0,14,16},
							/*C7*/{ 0, 0, 0, 0, 0,15,14, 0,18},
							/*C8*/{ 0, 0, 0, 0, 0, 0,16,18, 0},
							};
double distanciaMinima = 999999;

double longitud(Nodo<int>*, int);
bool esValido(Nodo<int>*);
void calcular(Nodo<int>*&, int, int, Nodo<int>*&, Nodo<int>*&, int);

int main() {
	Nodo<int> *inicioMapa = NULL, *inicioCamino = NULL, *finCamino = NULL, *p;
	int velocidad;
		
	//Establecimiento del primer órden
	for(int i = 0; i < 9; i++) {
		insertar<int>(inicioMapa, i);
	}
	
	
	cout << "Bienvenido" << endl << endl;
	cout << "Ingrese la velocidad promedio del movil: ";
	cin >> velocidad;
	
	calcular(inicioMapa, 1, 7, inicioCamino, finCamino, velocidad);
	
	p = inicioCamino;
	while(p!=NULL){
		cout << p->info << ", ";
		p = p->sig;
	}
}

/*
 * Función que calcula la longitud del camino
 * 
 * @param inicio puntero al inicio de la estructura donde está almacenado el camino
 * @param velocidad es la velocidad promedio del movil ingresada por el usuario
 * @return devuelve la longitud total del camino
 */
double longitud(Nodo<int> *inicio, int velocidad) {
	Nodo<int> *p = inicio;
	double longitudCamino;
		 
	while(p->sig != NULL) {
		longitudCamino += camino[p->info][p->sig->info] + (rand()/((double)RAND_MAX))*velocidad; 
		p = p->sig;
	}
	//cout << longitudCamino << endl;
	
	return longitudCamino;
}

/*
 * Función que determina si un camino es valido o no
 * 
 * @param inicio puntero al inicio de la estructura donde está almacenado el camino
 * @return devuelve true si es valido y false si no
 */
bool esValido(Nodo<int> *inicio) {
	Nodo<int> *p = inicio;
	while(p->sig != NULL) {
		if(!camino[p->info][p->sig->info]) {
			return false;
		}
		p = p->sig;
	}
	return true;
}

/*
 * Función recursiva que permuta el vector de todas las formas posibles y evalua cuál es el camino óptimo, ingresándolo en una cola.
 * 
 * @param p puntero que indica el comienzo de la estructura a permutar
 * @param inicio posición de inicio de la permutación
 * @param fin posición de fin de la permutación
 */
void calcular(Nodo<int> *&p, int inicio, int fin, Nodo<int> *&pCamino, Nodo<int> *&fCamino, int velocidad) {
	if(inicio == fin && esValido(p)) {
		//Caso de corte donde se comprueba si el camino es válido y se evalúa cuál es el óptimo
		
		//mostrar<int>(p);
		//cout << endl << endl;
		double distanciaActual = longitud(p, velocidad);
		
		if(distanciaActual < distanciaMinima) {
			//Si se encuentra un camino mejor, se elimina el camino previo de la cola de salida y se guarda el nuevo
			distanciaMinima = distanciaActual;
			Nodo<int> *q = p;
			vaciarCola<int>(pCamino, fCamino);
			while(q != NULL) {
				agregar<int>(pCamino, fCamino, q->info);
				q = q->sig;
			}
		}
	} else {
		//Recursividad que permite permutar la lista
		for(int i = inicio; i <= fin; i++) {
			swap<int>(p, inicio, i);
			calcular(p, inicio + 1, fin, pCamino, fCamino, velocidad);
			swap<int>(p, inicio, i);
		}
	}
}
