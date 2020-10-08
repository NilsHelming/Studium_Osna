/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: fstream.cpp
 * 
 * Demonstration zur Verwendung von Eingabe- und Ausgabestroemen.
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    //Eingbestrom anlegen und mit Datei "eingabe.txt" verbinden
    ifstream ein("eingabe.txt");
    //Ausgabestrom anlegen und mit Datei "ausgabe.txt" verbinden
    ofstream aus("ausgabe.txt");
    if (!ein || !aus)
    { //Pruefen ob die Datein geoeffnet wurden
        cout << "Fehler beim Oeffnen der Dateien" << endl;
        exit(1);
    }

    // Datei kopieren und dabei Werte verdreifachen
    double wert;
    while (!(ein >> wert).eof()) //Einlesen bis End of File
        aus << "Wert=" << setw(6) << 3 * wert << endl;
    ein.close();
    aus.close();
    cout << "Ende" << endl;
}
