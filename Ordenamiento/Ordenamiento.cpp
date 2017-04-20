#include <iostream>
#include <windows.h>
using namespace std;

int main(){
	
	int numeros[10], aux;
	
	//Ingreso de datos
	for(int i = 0; i < 10; i++){

		cout << "Ingrese el " << i + 1 << " numero: ";
		cin >> numeros[i];

	}
	
	//Ordenamiento
	for(int i = 0; i < 9; i++){
		
		for(int j = i + 1; j < 10; j++){
			
			if(numeros[j]<numeros[i])
			{
				aux = numeros[j];
				numeros[j] = numeros[i];
				numeros[i] = aux;
			}
					
		}
	
	}
	
	system("cls"); //Limpia la pantalla
	
	//Salida de datos
	for(int i = 0; i < 10; i++){
		cout << numeros[i] << endl;
	}

	return 0;
}
