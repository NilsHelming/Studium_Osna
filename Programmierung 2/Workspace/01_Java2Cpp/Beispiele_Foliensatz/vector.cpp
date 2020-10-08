/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: vector.cpp
 * 
 * Demonstration der Typschablone vector
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector> // Bibliothek fuer Vektoren
using namespace std;

int main()
{
    vector<double> vec{1.5, -2.3}; // Vektor fuer double-Werte
    vector<double> vec_kopie(vec); // Inhaltskopie von vec
    vector<int> quadrate(10);      // Vektor mit Platz fuer 10 int-Werte

    // Elemente anfuegen/entfernen
    vec.push_back(3.7); // 1.5, -2.3, 3.7
    vec.push_back(5.4); // 1.5, -2.3, 3.7, 5.4
    vec.pop_back();     // 1.5, -2.3, 3.7
    vec_kopie = vec;    // Wertzuweisung

    // Elementzugriff
    cout << vec.front() << " "; // 1.5
    cout << vec.back() << endl; // 3.7

    // wahlfreier Zugriff
    for (int i = 0; i < quadrate.size(); i++)
        quadrate[i] = i * i;
    // Anzahl Elemente--^                    ^--Elementselektion
    // 0 1 4 9 16 25 36, 49 64 81

    for (int i = 10; i < 15; i++)  // Elemente anfuegen:
        quadrate.push_back(i * i); // NICHT quadrate[i]=... !
    //quadrate.at(i)=i*i;          // at ueberprueft Indexbereich
    // 0 1 4 9 16 25 36 49 64 81 100 121 144 169 196

    // Globalzugriff
    quadrate.resize(10); // schneidet Vektor ab
    // 0 1 4 9 16 25 36 49 64 81
    quadrate.resize(15); // verlaengert Vektor
    // 0 1 4 9 16 25 36 49 64 81 0 0 0 0 0

    vec_kopie[2] = 3;
    cout << boolalpha << (vec_kopie < vec) << endl;
    // lexikographischer Vergleich: true
}
