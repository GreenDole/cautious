#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
/**
* brief функция выводит результат на экран
* param  x - локальные переменные, a - константа
* *return 0 - в случае успеха
*/

int main()
{
const double a = 2.5;
cout << "X=";
double x;
cin >> x;
double q;

q = x * pow(sin (x), 2);
if (q > a)
    cout << "from " << q << " to + infinity \n";
else
    cout<< "variable q is not defined\n";
double w;

w = x * pow(cos(x), 2);
if (w <= a)
    cout << " from - infinity to \n" << w;
else
    cout << "variable w is not defined\n";
return 0;
	
}