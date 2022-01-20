#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

/**
* brief функция выводит результат на экран
* param  x1, y1, x2, y2, x3, y3 - локальные переменные
* *return 0 - в случае успеха
*/

int main()
{
	double x1, y1, x2, y2, x3, y3;
	cout << "x1=";
	cin >> x1;
	cout << "y1=";
	cin >> y1;
	cout << "x2=";
	cin >> x2;
	cout << "y2=";
	cin >> y2;
	cout << "x3=";
	cin >> x3;
	cout << "y3=";
	cin >> y3;
	double a, b, c;
	a = sqrt(sqrt(abs(x1 - x2)) + sqrt(abs(y1 - y2)));
    b = sqrt(sqrt(abs(x2 - x3)) + sqrt(abs(y2 - y3)));
    c = sqrt(sqrt(abs(x1 - x3)) + sqrt(abs(y1 - y3)));
	double p;
    p = (a + b + c) / 2;
	double s;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
	if (s == 0)
		cout << "located on one straight\n";
	else 
		cout << "not located on one straight";
	return 0;
}