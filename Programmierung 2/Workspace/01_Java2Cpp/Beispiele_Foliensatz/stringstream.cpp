/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: stringstream.cpp
 * 
 * Demonstration zur Verwendung von Stroemen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <sstream> //Bibliothek von stringstream
using namespace std;

int main()
{
    string str = "12.345 45";
    float doubleVar = 0;
    int intVar = 0;

    //Konvertierung eines strings nach double und int
    stringstream strom(str);                        // Stromobjekt initialisieren
    if (!(strom >> doubleVar >> intVar))            // Probieren der Zuweisung
        cout << "error: could not convert" << endl; // nicht geklappt
    else
    { // hat geklappt - Ausgabe: 12.345 - 45
        cout << doubleVar << " - " << intVar << endl;
    }

    //Konvertierung von double und int in einen string
    stringstream neuerStrom;
    neuerStrom << doubleVar << " : " << intVar; // Konvertierung
    cout << neuerStrom.str() << endl;           // Umwandlung in string-Wert
                                                // Ausgabe: 12.345 : 45
}
