/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: op_elementarer_datentyp.cpp
 * 
 * Demonstration zur Ueberladung verschiedener Operatoren einer Klasse 
 * und der Verwendung von elementaren Datentypen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <vector>
#include <iostream>
using namespace std;

class K
{
    vector<double> werte;

public:
    K()
    {
        for (int i = 0; i < 100; ++i)
        {
            werte.push_back(i);
        }
    }
    //!
    //! typisches Beispiel I: Vergleichsoperatoren
    // in der Regel implementiert man nur
    bool operator==(const K &) const;
    bool operator<(const K &) const;
    // alle anderen Vergleichsoperatoren
    // sind davon abgeleitet
    bool operator!=(const K &rhs) { return !operator==(rhs); }
    bool operator<=(const K &rhs)
    {
        return (operator==(rhs) || operator<(rhs));
    }
    bool operator>(const K &rhs) { return !operator<=(rhs); }
    bool operator>=(const K &rhs) { return !operator<(rhs); }
    //!
    //! typisches Beispiel II: Indexoperator
    // Variante mit Schreibrecht auf den Vektorinhalten
    double &operator[](int i) { return werte[i]; }
    // Variante ohne Schreibrecht auf den Vektorinhalten
    const double &operator[](int i) const { return werte[i]; }
    // normalerweise beeinhaltet die Implementation auch
    // noch eine Gueltigkeitspruefung des uebergebenen Index i
};

int main()
{
    K k;
    cout << "50. Wert: " << k[50] << endl;
    return 0;
}
