/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: logische_Werte.cpp
 *
 * Demonstration von Wahrheitswerten
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    bool wahrheitswert{false}; // Initialisierung!

    cout << wahrheitswert << endl;
    cin >> wahrheitswert;                       // Eingabeaufforderung;
    cout << boolalpha << wahrheitswert << endl; // true, falls Eingabe != 0;

    return 0;
}
