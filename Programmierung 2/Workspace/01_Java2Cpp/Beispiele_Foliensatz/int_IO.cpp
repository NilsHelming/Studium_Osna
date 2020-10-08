/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: int_IO.cpp
 * 
 * Demonstration der Berechnung unterschiedlicher numerischer Basen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <iomanip> ///Manipulatoren
using namespace std;

int main()
{
    int dezZahl, hexZahl;

    cin >> hex >> hexZahl;
    // ^-- naechste Eingabe wird hexadezimal interpretiert!
    //     moegliche Ziffern: 0-9,A-F bzw. a-f
    //     Beispieleingabe: c
    cout << hexZahl
         << " (hex: " << hex << hexZahl << ")" << endl;
    // 12 (hex: c)

    dezZahl = 12;
    cout << "Zahlenbasen:" << endl;
    cout << showbase; // Zahlenbasis bei Ausgabe anzeigen
    cout << "oct: " << oct << setw(4) << dezZahl << ", ";
    cout << "hex: " << hex << uppercase << setw(4) << dezZahl << ", ";
    cout << "dec: " << dec << setw(4) << setfill(' ') << showpos << dezZahl << endl;
    cout << noshowbase; // auf Standard zuruecksetzen
        // oct:  014, hex:  0XC, dec:  +12

    return 0;
}
