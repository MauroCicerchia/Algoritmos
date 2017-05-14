#include <iostream>
using namespace std;

int suma (int, int);
int doble(int);
int mitad(int);

int main()
{
	int a, b;
	
	cout << "Ingrese el valor a: ";
	cin >> a;
	
	cout << "Ingrese el valor b: ";
	cin >> b;
	
	cout << "Suma: " << suma(doble(a), mitad(b));
}

int suma(int a, int b)
{
	return a+b;
}

int doble(int a)
{
	return (2*a) + 1;
}

int mitad(int b)
{
	return (b/2) -1;
}
