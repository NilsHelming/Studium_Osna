/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: Typumwandlung_Gefahren2.cpp
 * 
 * Beispiel von compilerabhaengigen und damit nicht portablen Code
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

/* 
 * sogenannte VORWAERTSDEKLARATION der Klasse B:
 * Hier wird lediglich bekannt gemacht, dass es eine Klasse B
 * gibt.
 * Nachfolgende Definitionen koennen dann die Existenz des Datentyps B 
 * voraussetzen
 */
class B;

/*
 * Klasse A, die den Datentyp B verwendet
 */
class A
{
  int wert;

public:
  A(int x) : wert(x) {}
  A(const B &) { wert = 1; } // Typwandlung B-->A

  int get_v() const { return wert; }
};

/*
 * Definition der Klasse B, die wiederum den Datentyp A verwendet
 */
class B
{
public:
  operator A() { return A(2); } // Typwandlung B-->A
};

/*
 * Demo
 */
int main()
{
  B b;                              // Welche Typwandlung findet statt?
  cout << static_cast<A>(b).get_v() // --> Compilerabhaengig
       << endl;
}
