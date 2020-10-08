/*
* -----------------------------------------------------------------------------
*
* Beispielprogramm: sichereEingabe.cpp
*
* Beispielprogramm zum Testen fehlerhafter Eingaben.
*
* VL Programmierung 2, O. Henkel, HS Osnabrueck
* -----------------------------------------------------------------------------
*/
#include <iostream>
using namespace std;

int main () {
 
 int zahl;                  // einzulesende Werte
 int ungueltigeZeichen=0;   // Zeichen, die keine Ziffern sind
 char falschesZeichen =' '; // nimmt die Falscheingaben auf
 
 cout << "Bitte eine Zeile, die Zahlen enthaelt, eingeben" << endl;
 
 do { // Eingabe wird Zeichen fuer Zeichen durchgegangen
  cin >> noskipws >> zahl; // Einlesen der Zahl
  //     ^-- Manipulator: Whitespace-Charaktere werden ab jetzt
  //                      als normale Zeichen eingelesen
  if (cin.fail()) {        // Abfrage des Eingabestrom-Zustands:
   // fail() liefert true, wenn der Eingabestrom fuer
   // die naechste Eingabe nicht bereit ist
   // z.B. weil das naechste Zeichen ein Buchstabe ist
   cin.clear();           // macht den Strom wieder aufnahmebereit
   cin >> noskipws >> falschesZeichen; // Aufnahme des ungueltigen Zeichens
   // in den dafuer vorgesehenen Datentyp
   ungueltigeZeichen++;   // ungueltige Zeichen zaehlen
  } // if
  else {
   cout << "akzeptierter Wert: " << zahl << endl;
  } // else
 } while(falschesZeichen != '\n');  // Pruefung, ob die Schleifen erneut
 // durchlaufen werden soll
 
 ungueltigeZeichen--;  // Das letzte '\n' war nicht ungueltig
 cout << endl;
 cout << "Es wurden " << ungueltigeZeichen
 << " ungueltige Zeichen ueberlesen" << endl;
 
 return 0;
}
