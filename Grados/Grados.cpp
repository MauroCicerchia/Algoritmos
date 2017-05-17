#include <iostream>
using namespace std;

float toCelsius(float);

int main() {
	float grados;
	
	cin >> grados;
	cout << toCelsius(grados);
}

float toCelsius(float g) {
	return (g - 32)/1.8;
}
