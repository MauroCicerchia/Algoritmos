#include <iostream>
using namespace std;

void multiplos(int);

int main()
{
	int num;
	
	cout << "Ingrese un numero para mostrar sus multiplos: ";
	cin >> num;
	
	system("cls");
	
	multiplos(num);
}

void multiplos(int num)
{
	for(int i = 2; i <= 51; i++)
		cout << num*i << " ";
}
