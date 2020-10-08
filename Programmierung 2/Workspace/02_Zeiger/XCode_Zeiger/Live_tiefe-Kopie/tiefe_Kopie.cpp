/*
 * -----------------------------------------------------------------------------
 *
 * Liveprojekt: tiefe_Kopie.cpp
 *
 * int-Array fuer ein dynamisches Feld mit waehlbaren Indexbereich
 * [min,max).
 *
 ****
 * Ziel:
 * - Implementation einer tiefen Kopie in KK und operator=
 ****
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Klasse fuer ein dynamisches Feld, dessen Indexbereich bei der Erzeugung
 * angegeben werden kann;
 * Zu Vorfuehrzwecken wird die Klasse hier bei der Vereinbarung sofort
 * implementiert
 */
class Array {
  int size, min,max;
  int *data;
public:
  // Konstruktor/Destruktor
  Array() : size(0), min(0), max(0),
            data(0)                       {}
  Array(int _min, int _max) :
    size(_max-_min), min(_min), max(_max),
    data(new int[size])                     {}
  ~Array()               { delete [] data; }

  // Kopierkonstruktor --- tiefe Kopie
  Array(const Array& orig):
   size(orig.size), min(orig.min), max(orig.max),
 data(new int[size])  // Speicher bereitstellen fuer tiefe Kopie
 {                    // ...und elementweise kopieren
  for (int i=0; i<size; i++) data[i]=orig.data[i];
 }

  // Zuweisungsoperator --- tiefe Kopie
  // Unterschied zum KK: Objekt auf der linken Seite der Zuweisung
  // existiert bereits (mit Daten)
 Array& operator=(const Array& orig) {
  if (this==&orig) return *this;  //! notwendig bei Selbstzuweisung
  size=orig.size;
  min=orig.min;
  max=orig.max;
  delete[] data;      // bereits vorhandenen Daten auf der linken Seite freigeben
  data=new int(size); // passenden Speicher (rechte Seite) bereitstellen
  for (int i=0; i<size; i++) data[i]=orig.data[i]; // ...und fuellen
  return *this;
 }

  // []-Operator
  int& operator[](int i) {
    if (i<min or i>=max)
      throw "Array::Bereichsueberschreitung" ;
    return data[i-min];
  }
  // Methoden
  int Min() { return min; }
  int Max() { return max; }
  void info() {
    cout << setw(2) << size << " [" << min << ',' << max << ") | ";
    for(int i=0; i<size; i++)
      cout << setw(3) << data[i] << " ";
    cout << endl;
  }
};


/*
 * Demonstration
 */
int main() {

  Array a(10,15);  // integer-Feld mit 5 Elementen
  for(int i=a.Min();i<a.Max();i++) a[i]=i*i;

  Array b(a);      // tiefe Kopie anlegen

  Array c;
  c=a;                  // tiefe Zuweisung vornehmen
  c=c;

  a[10]=1;
  a.info();
  b.info();
  c.info();

  return 0;             // Destruktoraufrufe wuerden bei flacher Kopie
}                       // einen Laufzeitfehler verursachen!
