/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: typumwandlung.cpp
 * 
 * Demonstration von Typumwandlungen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

class Zahl
{
private:
    int inhalt;

public:
    Zahl(int _inhalt) : inhalt(_inhalt) {}
    operator int() { return inhalt; }
    // Der Rueckgabetyp des Typumwandlungsoperators ist
    // sein Name (keine explizite Angabe!)
};

int main()
{
    Zahl z(5);
    int ergebnis = 8 + z;
    cout << "Ergebnis: " << ergebnis << endl;
}