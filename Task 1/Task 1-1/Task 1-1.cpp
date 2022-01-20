#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

/**
* brief функция вычисляет a
* param x,y,z - констант
*/
double getA(const double x, const double y, const double z);

/**
* brief функция вычисляет b
* param x,y,z - константы
*/
double getB(const double x, const double y, const double z);

/**
*brief функция выводит результат на экран
*return 0 - в случае успеха
*/
int main()
{
	const double x = 0.61;
	const double y = 3.4;
	const double z = 16.5;
	cout << "embedded constants: x=0.61 y=3.4 z=16.5\n";
	double a = getA(x, y, z);
	cout << "a = " << a;
	double b = getB(x, y, z);
	cout << "  b = " << b;
}

double getA(const double x, const double y, const double z) {
	return (pow(x, 3) * pow(tan(pow(x + y, 2)), 2)) + (z / sqrt(x + y));
}

double getB(const double x, const double y, const double z) {
	return (y * pow(x, 2) - z) / (exp(z * x) - 1);
}