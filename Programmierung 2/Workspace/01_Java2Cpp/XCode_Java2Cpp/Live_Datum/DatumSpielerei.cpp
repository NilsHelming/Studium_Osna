/*
 * -----------------------------------------------------------------------------
 * 
 * Liveprojekt: DatumSpielerei.cpp
 * 
 * Demonstration der Moeglichkeiten der Klasse Datum
 *
 * Demonstration:
 * --> sichere Objektkonstruktion/Manipulation der Attribute
 * --> Ein- und Ausgabe
 * Weiteres Ziel:
 * --> Implementation von Operatoren
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;
#include "Datum.h"

int main() {
 Datum semesterstart(1,3,2020);
 Datum vorlesungsstart("2.3.2020");
 Datum vorlesungsende("12.6.2020");
 Datum semesterende(31,8,2020);
  
 cout << "Semesterstart:   " << semesterstart << endl;
 Datum::klarnameMonat=true;
 cout << "Vorlesungsstart: " << vorlesungsstart << endl;
 cout << "Vorlesungsende:  " << vorlesungsende << endl;
 Datum::klarnameMonat=false;
 cout << "Semesterende:    " << semesterende << endl;
 
 //
 // Test der Vergleichsoperatoren
 cout << endl;
 cout << "Vergleiche: (erwartet: true, true, false)" << endl;
 cout << boolalpha << (vorlesungsstart==Datum("2.3.2020")) << ", ";
 cout << boolalpha << (semesterstart<vorlesungsstart) << ", ";
 cout << boolalpha << (semesterstart>=semesterende) << endl;
 
 //
 // Demonstration der Addition/Subtraktion von Tagen
 cout << endl;
 cout << "Test: Inkrement/Addition" << endl;
 Datum jahresanfang("1.1.2020");
 cout << jahresanfang++ << endl;
 cout << jahresanfang << endl;
 
 Datum fuenfzigNachStart=vorlesungsstart+50;
 cout << "Vorlesungsstart plus 50 Tage: " << fuenfzigNachStart << endl;
 
 cout << endl;
 cout << "Test: Datumsdifferenz" << endl;
 long vorlesungszeit=vorlesungsende-vorlesungsstart;
 cout << "Vorlesungszeit:  " << vorlesungszeit << " Tage" << endl;
 cout << "Semesterdauer:   "  << semesterende-semesterstart << " Tage" << endl;
 
 string heute("23.13.2020");  // Fehler!
 try {
 cout << "Semesterdauer bis " << heute << ": " 
      << static_cast<Datum>(heute)-semesterstart  
         // explizit angeforderter Konstruktoraufruf zur Typwandlung
      << " Tage" << endl;
 }
 catch (const UngueltigesDatum& ud) {
  cout << "Achtung: Falsches Datum gesetzt." << endl;
  cout << "Quelle dieser Meldung: Datei " 
       << __FILE__ << ", Zeile " << __LINE__ << endl;
  cout << "Hier koennte jetzt eine Fehlerbehandlung stattfinden..." << endl;
  //heute="23.3.2020";
  //...und neuer Versuch mittels do-while-Schleife...
 }
  
 cout << "Zeit seit Kalenderbeginn: " 
      << (Datum("23.3.2020")-Datum(1,1,0))
      << " Tage" << endl;
 
 return 0;
}
