#include <iostream>
#include <cmath>
using namespace std;
/**
* brief функция выводит результат на экран
* param  x1, x2, y1, y2 - локальные переменные
* *return 0 - в случае успеха
*/
int main()
{
	int x1, x2, y1, y2;
	cout << "Hello, print coordinates: \n";
	cout << "coordinates of point x1: \n";
	cin >> x1;
	cout << "coordinates of point x2: \n";
	cin >> x2;
	cout << "coordinates of point y1: \n";
	cin >> y1;
	cout << "coordinates of point y2: \n";
	cin >> y2;
	cout << "the distance is found by the formula: \n";
	cout << "sqrt(pow(x2-x1,2)+pow(y2-1,2))\n";
	int z;
	z = sqrt(pow(x2 - x1, 2) + pow(y2 - 1, 2));
	cout << "the distance between the points is: " << z << endl;
	return 0;

}