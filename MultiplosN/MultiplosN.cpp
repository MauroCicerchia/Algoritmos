#include <iostream>
using namespace std;

void calcularMultiplos(int, int, int);

int main()
{
	int n, a, b;
	
	cout << "Ingrese el numero n: ";
	cin >> n;
	
	cout << "Ingrese el numero a: ";
	cin >> a;
	
	cout << "Ingrese el numero b: ";
	cin >> b;
	
	calcularMultiplos(n, a, b);
}

void calcularMultiplos(int n, int a, int b)
{
	int multiplo, i;
	
	if(a < b && n <= b) 	//En caso de que a sea menor que b 
	{
		
		for(i = 1; multiplo <= b; i++)
		{
			multiplo = n*i;
			
			if(multiplo >= a && multiplo <= b)	//Si esta en el rango a-b
				cout << multiplo << " ";
		}
		
	} else {
		
		if(a > b && n <= a)	//En caso de que a sea mayor que b
		{
			
			for(i = 1; multiplo <= a; i++)
			{
				multiplo = n*i;
				
				if(multiplo >= b && multiplo <= a)	//Si esta en el rango b-a
					cout << multiplo << " ";
			}
			
		} else {
	
			if(a == b)	// Si a y b son iguales
			{	
				if(a >= n && a % n == 0)	// Si a es multiplo de n
				{
					cout << a;
				}
				
			}
			
		}
		
	}
	
}
