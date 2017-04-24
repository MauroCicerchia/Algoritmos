#include <iostream>
using namespace std;

long int factorial(int N)
{
    if (N >= 1)
        return N*factorial(N-1);
    else
        return 1;
}

int main()
{
	int N;
	
	cout << "Ingrese el numero para calcular su factorial: ";
	cin >> N;
	
	cout << "El factorial es: " << factorial(N);
}
