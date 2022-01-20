#include <iostream> 
#include <conio.h> 
#include <math.h> 

using namespace std;

/**
* brief функция выводит результат на экран
* param x,dx - константы 
* *return 0 - в случае успеха
*/


int main()
{
	const double x = 2, dx = 0.2;
	double y, s;
	cout << "x: " << "\t y: " << endl;
	while (x <= 4)
	{
		y = (3 * x) - (4 * log(fabs(x))) - 5;
		if (x == 0)
			cout << x << "\t-" << endl;
		else
			cout << x << "\t" << y << endl;
		s += dx;
	}
	return 0;
}