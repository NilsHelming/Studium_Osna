/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: sichtbarkeit.cpp
 * 
 * Demonstration von Sichtbarkeiten in einer Klassen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

class K
{             // immer public
    int i{0}; // Voreinstellung 'private'

protected: // ab hier: protected
    int j{0};

public:               // ab hier: public
    K() {}            // oeffentlicher Konstruktor
    void methode() {} // oeffentliche Methode
};                    // Semikolon nicht vergessen!

int main()
{
    K k;
    k.methode(); // nur oeffentliche Methode 'methode' ist hier sichtbar

    return 0;
}
