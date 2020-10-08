/*
 * -----------------------------------------------------------------------------
 *
 * Liveprojekt: Datum.h
 *
 * Vereinbarung der Klasse Datum mit zugehoerigen Methoden und Funktionen
 * ToDo: Vergleichs-/Inkrement/Add-/Subtraktionsoperatoren
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#ifndef DATUM_H
#define DATUM_H


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef unsigned short ushort;

/*
 * Ausnahmeklasse zum Auffangen von ungueltigen Datumsobjekten
 */
class UngueltigesDatum {
 ushort tag;
 ushort monat;
 ushort jahr;
 string datei;
 int    zeile;
public:
 UngueltigesDatum(ushort _tag, ushort _monat, ushort _jahr,
                  const string& _datei, int _zeile)
 : tag(_tag), monat(_monat), jahr(_jahr), datei(_datei), zeile(_zeile) {}
 string meldung() const {
  ostringstream sout;
  sout << "Ausnahme in Datei " << datei << ", Zeile " << zeile<< endl;
  sout << "Es wurde versucht ein Datumsobjekt mit folgenden Daten zu erzeugen:"
  << endl;
  sout << tag << "." << monat << "." << jahr << endl;
  return sout.str();
 }
};

/*
 * Die Datumsklasse
 */
class Datum {
private:                // kann entfallen, ist default
 ushort tag;           // Auf private Komponenten kann von ausserhalb der
 ushort monat;         // Klasse nicht zugegriffen werden
 ushort jahr;
public:                 // Ab hier: oeffentlich zugaengliche Komponenten
 //
 // Konstruktoren / Standardmethoden
 // Anforderung: korrekte Datumskonstruktion
 
 // Konstruktor mit Parametern
 Datum(ushort _tag, ushort _monat, ushort _jahr);
 // Datumskonstruktion aus string-Zeile
 explicit Datum(const string& datumstext);
 // ^-- explicit verhindert ungewollte "Typkonvertierung" string --> Datum
 //     vgl. Implementation von istream& operator>>(istream& strom, Datum& dat)
 //     in Datum.cpp
 // Kopierkonstruktor
 Datum(const Datum& _datum);
 // Destruktor, inline; nichts zu tun
 ~Datum() {}
 // Zuweisungsoperator
 Datum& operator=(const Datum& _datum);
 
 //
 // Getter und Setter fuer die Datenkomponenten (inline)
 ushort gibTag()   const { return tag; }
 ushort gibMonat() const { return monat; }
 ushort gibJahr()  const { return jahr; }
 void setzeTag(ushort _tag)
 {
  if (!istGueltig(_tag,monat,jahr))
   throw UngueltigesDatum(_tag,monat,jahr,__FILE__,__LINE__);
  tag=_tag;
 }
 void setzeMonat(ushort _monat)
 {
  if (!istGueltig(tag,_monat,jahr))
   throw UngueltigesDatum(tag,_monat,jahr,__FILE__,__LINE__);
  monat=_monat;
 }
 void setzeJahr(ushort _jahr)
 {
  if (!istGueltig(tag,monat,_jahr))
   throw UngueltigesDatum(tag,monat,_jahr,__FILE__,__LINE__);
  jahr=_jahr;
 }
 
 //
 // Dienste rund um die Gueltigkeitspruefung
 //
 // Hilfsfunktionen
 static bool istSchaltjahr(ushort _jahr);
 static ushort letzterTagImMonat(ushort _monat, ushort _jahr);
 // die statische Gueltigkeitspruefung ist hilfreich in den setter-
 // Methoden, da nicht extra ein Objekt erzeugt werden muss
 static bool istGueltig(ushort _tag, ushort _monat, ushort _jahr);
 // die objektgebundene Gueltigkeitspruefung nutzt die Implementation
 // der statischen Methode
 bool istGueltig() const { return istGueltig(tag,monat,jahr); }
 
 //
 // Darstellung der Monate
 static bool klarnameMonat;
 static vector<string> monatsname;
};

//
// Ein- und Ausgabe
//   --> erwarten als ersten Operanden ein Strom-Objekt und koennen
//       daher nicht innerhalb der Klasse Datum vereinbart werden
ostream& operator<<(ostream&, const Datum&);
istream& operator>>(istream&, Datum&);


#endif /* DATUM_H */

