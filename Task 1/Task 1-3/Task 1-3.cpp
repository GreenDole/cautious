#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

/**
* brief функция выводит результат на экран
* param m,s,q - локальные переменные
* return 0 - в случае успеха
*/

int main()
{
	double m, s, g;
	cout << "Hello, print the value: \n"; //Используйте метры
	cout << "weight: \n";
	cin >> m;
	cout << "square: \n";
	cin >> s;
	g = 10;
	double f, p;
	cout << "find the force of pressure: \n";
	f = m * g;
	cout << "f = m * g = \n" << f << endl;
	cout << "find the pressure: \n";
	p = f / s;
	cout << "p = f / s = \n" << p << endl;
	cout << "answer: \n" << p << endl;
	return 0;


}