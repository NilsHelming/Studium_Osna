/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: Standardmethoden.cpp
 * 
 * Demonstration zur Verwendung von Standardmethoden (bspw. toString())
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <initializer_list>
using namespace std;

class K
{
    size_t anz{0};
    vector<int> vec;

public:
    K() = default; // Standardkonstruktor behalten
    K(size_t);     // Ueberladung
    K(initializer_list<int>);
    K(const K &);            // Kopierkonstruktor
    K &operator=(const K &); // Zuweisungsoperator
    ~K() = default;          // Standarddestruktor verwenden

    const string toString();
};

//                v-- leitet Initialisierungsliste ein
K::K(size_t _anz) : anz(_anz), vec(_anz) {}
//    Vektor mit vorgegebener Laenge --^

K::K(initializer_list<int> liste) : anz(liste.size())
{
    for (int wert : liste)
        vec.push_back(wert);
}

K::K(const K &orig)
    : anz(orig.anz), vec(orig.vec) {}

K &K::operator=(const K &rhs)
{
    anz = rhs.anz;
    vec = rhs.vec;
    return *this;
}

const string K::toString()
{
    stringstream strom;
    strom << vec.size() << "| ";
    for (int wert : vec)
        strom << wert << " ";
    return strom.str();
}

K f(K k) { return k; }

int main()
{
    K k1; // Anlegen mit SK
    cout << k1.toString() << endl;
    K k2(1); // Anlegen mit ueberladenem Konstruktor
    cout << k2.toString() << endl;
    K k3{1}; // Initialisierung: Auswahl passender Konstruktor
             // Sequenzkonstruktor hat Vorrang
    cout << k3.toString() << endl;
    K k4{1, 2, 3, 4, 5, 6};
    cout << k4.toString() << endl;

    k1 = k4; // kopiert Inhalte
    cout << k1.toString() << endl;

    k2 = f(k4); // 2*KK + 2*D ! --> besser: Referenzuebergabe
    cout << k2.toString() << endl;

} // Destruktoraufruf fuer k1, k2, k3
