/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: statischerDynamischerTyp.cpp
 *
 * Verwendungsbeispiel fuer Basisklassenzeiger.
 * Was geht, was geht nicht.
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;


class B {
public:
  int x;
};

class U : public B {
public:
  int y;
};


void f(B*) {}
void g(U*) {}


int main () {
  B* pB;       // statischer Typ: B
  B b;         // B-Objekt
  U* pU;       // statischer Typ: U
  U u;         // U-Objekt


  pB = &b;     // Bindung des Zeigers pB an B-Objekt
  pB->x=1;     // Komponentenzugriff
  f(pB);       // OK
  //g(pB)      // nicht OK: falscher Parametertyp
  cout << "pB=&b: " << pB->x << endl;


  pB = &u;     // Bindung des Zeigers pB an U-Objekt
  pB->x=2;     // OK
  //pB->y=3;   // nicht OK: y ist keine Komponente im statischen Typ B,
               // d.h. der Compiler kann die Gueltigkeit des Ausdrucks nicht
               // ueberpruefen
  f(pB);       // OK
  //g(pB)      // nicht OK: falscher (statischer) Parametertyp
  cout << "pB=&u: " << pB->x << endl;


  pU = &u;     // Bindung des Zeigers pU an U-Objekt
  pU->x=4;     // OK: Komponente x ist in Klasse U (geerbt) vorhanden
  pU->y=5;     // OK: y ist nun im statischen Typ U von pU
  f(pU);       // OK: Compiler akzeptiert ein U* fuer ein B*
  g(pU);       // OK: richtiger Parametertyp
  cout << "pU=&u: " << pU->x << "," << pU->y << endl;


  //pU = &b;   // nicht OK


  return 0;
}
