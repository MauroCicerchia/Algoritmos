#include <iostream>
using namespace std;

int main()
{
	int num, N, max, min, pos = 0, neg = 0;
	
	cout << "Cantidad de numeros a ingresar: ";
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cout << "Ingrese el numero " << i+1 << ": ";
		cin >> num;
		
		//Determinación de positivos y negativos
		if(num==0)
		{
			cout << "El numero 0 no es un numero valido." << endl;
			i--;
		} else if(num > 0) {
			pos++;
		} else {
			neg++;
		}
		
		//Máximo y mínimo
		if(i==0){
			max = num;
			min = num;
		} else if(num > max) {
			max = num;
		} else if(num < min) {
			min = num; 
		}
	}
	
	//Salida
	cout << "Menor: " << min << endl;
	cout << "Mayor: " << max << endl;
	cout << "Numeros Positivos: " << pos << endl;
	cout << "Numeros Negativos: " << neg << endl;
	cout << "Porcentaje de positivos: " << ((float)pos/(float)N)*100.00 << "%" << endl;
	cout << "Porcentaje de positivos: " << ((float)neg/(float)N)*100.00 << "%" << endl;
	
	return 0;
}
