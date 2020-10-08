/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: referenztypen.cpp
 * 
 * Demonstration von Referenztypen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

int main()
{
    int i{1};
    int &i_ref{i}; // i_ref ist Referenz auf i
    int j{i};      // Initialisierung von j mit dem Wert von i

    j = i_ref; // Dasselbe wie j = i
    i_ref = 2; // Dasselbe wie i = 2
    j = 3;
    i = j;

    cout << i << " " << i_ref; // Ausgabe: 3 3

    return 0;
}