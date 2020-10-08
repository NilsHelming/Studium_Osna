/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Vererbung_C++.cpp
 *
 * Daten/Methoden-Zugriff in Basis- und abgeleiteten Klassen
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#include <iostream>
using namespace std;


class Basis {
 public:
  int x;
  void f() {}
};

class Unter: public Basis {
 public:
  int y;
  void g() {}
};

void func (Basis b) { b.x=5;        cout << "func (Basis)" << endl; }
void funcB(Basis b) { b.x=5;        cout << "funcB(Basis)" << endl; }
void func (Unter u) { u.x=5; u.y=6; cout << "func (Unter)" << endl; }
void funcU(Unter u) { u.x=5; u.y=6; cout << "funcU(Unter)" << endl; }

int main() {
  Basis b;   // Datenkomponente  x;   Methode  f
  Unter u;   // Datenkomponenten x,y; Methoden f,g

  b.x=1;     // OK
  b.f();     // OK

  u.x=2;     // OK
  u.y=3;     // OK
  u.f();     // OK
  u.g();     // OK

  func(b);      // OK: Aufruf von func(Basis)
  func(u);      // OK: Aufruf von func(Unter),
                //     da Kandidat func(Unter) besser als func(Basis) passt
                //                 ^                      ^-- Kriterium-3
                //                 |                          Uebereinstimmung
                //                 -- Kriterium-1 Typ-Uebereinstimmung

  funcB(b);     // OK
  funcB(u);     // OK, denn "u ist auch ein b" (Upcast Unter --> Basis)
  //funcU(b);   // nicht OK, da keine Typkonvertierung Basis-Unter vorhanden
  funcU(u);     // OK

  return 0;
}
