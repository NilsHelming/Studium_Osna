/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Kommandozeilenparameter.cpp
 *
 * Uebergabe von Parametern an ein Programm
 * Beispielprogramm liest alle uebergebenen Parameter aus und
 * gibt sie auf den Bildschirm aus
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;


int main(int nParameter, char *parameter[]){
    //       ^                 ^-- Feld von Zeigern auf char!
    //       |                     Jeder Zeiger zeigt auf den Anfang einer
    //       |                     Zeichenkettenkonstante
    //       |                     (=uebergebener Parameter)
    //       -- Anzahl Parameter
    //          (stets mindestens 1, da der Dateiname des ausfuehrenden
    //           Programms ebenfalls als Parameter gezaehlt wird)


//
// Auslesen und Ausgabe der Parameter
 for(int i=0; i<nParameter; ++i)
   cout << parameter[i] << " ";
 cout << endl;

//
//Variante mit Zeigerarithmetik
  do {
    cout << *parameter << " ";
  } while(NULL != *++parameter);         // *(++parameter)
//} while(NULL != (++parameter)[0]);     // Klammerung!
  cout << endl;


 return 0;
}
