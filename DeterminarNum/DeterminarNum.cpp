#include <iostream>
using namespace std;

int main()
{
	int num, pos = 0, neg = 0, z = 0;
	
	for(int i = 1; i <= 10; i++)
	{
		cout << "Ingrese el numero " << i << ": ";
		cin >> num;
		
		if(num == 0)
			z++;
		else
			if(num < 0)
				neg++;
			else
				pos++;
	}
	
	cout << "Positivos: " << pos << endl;
	cout << "Negativos: " << neg << endl;
	cout << "Ceros: " << z << endl;
}
