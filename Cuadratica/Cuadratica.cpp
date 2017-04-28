#include <iostream>
#include <math.h>
using namespace std;

bool determinarRaices(int, int, int, float&, float&);

int main()
{
	int a, b, c;
	float x1, x2;
	
	cout << "Ingrese el coeficiente a: ";
	cin >> a;
	
	cout << "Ingrese el coeficiente b: ";
	cin >> b;
	
	cout << "Ingrese el coeficiente c: ";
	cin >> c;
	
	system("cls");
	
	if(determinarRaices(a, b, c, x1, x2))
	{
		if(x1 == x2)
			cout << "La raiz es doble y es " << x1;
		else
			cout << "Las raices son simples y son " << x1 << " y " << x2;
	} else {
		cout << "No existen raices reales";
	}
}

bool determinarRaices(int a, int b, int c, float &x1, float &x2)
{
	if((pow(b, 2) - 4*a*c) == 0)
	{
		x1 = -b/2*a;
		x2 = x1;
		
		return true;
	} else {
		if((pow(b, 2) - 4*a*c) > 0)
		{
			x1 = (-b + sqrt(pow(b, 2) - 4*a*c)) / 2*a;
			x2 = (-b - sqrt(pow(b, 2) - 4*a*c)) / 2*a;
			
			return true;
		} else {
			return false;
		}
	}
}
