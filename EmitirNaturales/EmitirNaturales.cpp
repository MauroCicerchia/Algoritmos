#include <iostream>
using namespace std;

void printN(int R, int N)
{
	for(int i = 0; i<N; i++){
		cout << R + i << endl;
	}	
}

int main()
{
	int R, N;
	
	cout << "Ingrese el numero inicial: ";
	cin >> R;
	
	cout << "Ingrese la cantidad de numeros: ";
	cin >> N;
	
	printN(R, N);
	
	return 0;
}
