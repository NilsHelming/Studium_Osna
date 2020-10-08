/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: datentypen.cpp
 * 
 * Demonstration impliziter Typkonvertierungen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

int main()
{
    double a = -3.7 + 5; // 5 --> 5.0 vor Addition
    double x = 5 + 8;    // 13 --> 13.0 vor Zuweisung
    cout << (-3.7 || 0); // -3.7 --> true, 0 --> false
    return 0;
}
