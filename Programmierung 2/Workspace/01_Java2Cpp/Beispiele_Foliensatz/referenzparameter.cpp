/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: referenzparameter.cpp
 * 
 * Demonstration von Swap
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

void ausgabe(int a, int b)
{
    cout << "a: " << a << "\tb: " << b << endl;
}

void swap(int &x, int &y)
{
    int hilf{x};
    x = y;
    y = hilf;
}

int main()
{
    int a{1};
    int b{2};
    ausgabe(a, b);
    swap(a, b);
    ausgabe(a, b);

    return 0;
}
