/*
 * -----------------------------------------------------------------------------
 * 
 * Uebung: uebung_person_2.cpp
 * 
 * Kopier- und Zuweisungsoperator
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

class Test
{
    int i; // private Komponente
    // ... - weitere Komponenten
public:
    Test() : i(0) {}                   // Standardkonstruktor - initialisiert i mit 0
    Test(const Test &t) { *this = t; } // Kopierkonstruktor - Verweis auf t
    Test operator=(const Test &t)      // Überladener '='-Operator
    {
        i = t.i;
        return *this;
    }
    void put(const int v) { i = v; }
    int get() { return i; }
};

int main()
{
    Test t;     // Initialisiere Instanz von Test
    Test tt(t); // Initialisiere durch Kopierkonstruktor
    cout << t.get() << " " << tt.get() << endl;
    return 0;
}
