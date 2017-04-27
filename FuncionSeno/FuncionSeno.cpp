#include <iostream>
#include <math.h>
using namespace std;

const float pi = 3.141592654;

float sen(float);

int main()
{
	float x = (pi/3);
	
	cout << sen(x);
}

float sen(float ang)
{
	float result;
	
	//Encuadra el �ngulo en el rango 0-2pi
	while(ang < 0 || ang >= (2*pi))
	{
		if(ang < 0)
			ang += (2*pi);
		else
			ang -= (2*pi);
	}
		
	//Si esta en el segundo cuadrante
	if(ang > (pi/2) && ang <= pi){
		ang = pi - ang;
	}
	
	//Si esta en el tercer cuadrante
	if(ang > pi && ang <= (pi*3/2))
		ang = -1*(ang - pi);
		
	//Si esta en el cuarto cuadrante
	if(ang > (pi*3/2) && ang < (2*pi))
		ang -= (2*pi);
		
	//Angulo encuadrado entre pi/2 y -pi/2
	result = ang - (pow(ang, 3)/6 ) + (pow(ang, 5)/120);
	
	return result;
}
