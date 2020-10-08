/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: addiere.cpp
 * 
 * Demonstration eines Beispielprogramms mit Addition
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

int addiere(int, int); // Funktionsdeklaration

int main()
{
    int a{4}, b{5}, c;
    c = addiere(a, b);
    cout << c;
    return 0;
}

int addiere(int a, int b)
{ // Funktionsimplementation
    return a + b;
}
