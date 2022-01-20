#include <iostream>
using namespace std;

/**
*brief функция выводит результат на экран
* param a,b - локальные переменные
*return 0 - в случае успеха
*/

int main()
{
    int a, b;
    cout << "Enter number a:";
    cin >> a;
    cout << "Enter number b:";
    cin >> b;

    cout << "Choose a solution method:\n";
    cout << "1.Method: selected using third variable C\n";
    cout << "2.Method: without using the third variable\n";
    int d;
    cout << "Print: 1 or 2\n";
    cin >> d;
    if (d == 1) {
        cout << "Used method 1.";
        int c;
        c = a;
        a = b;
        b = c;
        cout << "The values have changed!\n";
        cout << a << "  and  " << b << endl;
        return 0;
    }
    else if (d == 2) {
        cout << "Used method 2.";
        a = a + b;
        b = b - a;
        b = -b;
        a = a - b;
        cout << "The values have changed!\n";
        cout << a << "  and  " << b << endl;
        return 0;
    }
    else {
        cout << "Incorrect input, used only nambers 1 or 2";
        return 0;
    }
}