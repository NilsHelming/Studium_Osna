/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: enum.cpp
 * 
 * Demonstration zur Verwendung von Aufzählungen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

int main()
{
    // Neuer Aufzaehlungstyp Ampel
    enum Ampel
    {
        rot,
        gelb,
        gruen
    };

    // eine Ampelvariable
    Ampel ampel_ecke_lessingstrasse = rot;

    //
    if (ampel_ecke_lessingstrasse == rot)
    { /* warten */
    }

    // Ampel weiterschalten
    ampel_ecke_lessingstrasse = gruen;
    int interneNr{ampel_ecke_lessingstrasse}; // 2
    cout << interneNr << endl;
    cout << gruen << endl;

    return 0;
}
