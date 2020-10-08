/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Zuweisungsoperator.cpp
 *
 * Fuer selbsterstellte Zuweisungsoperatoren gilt:
 * In abgeleiteten Klassen muss der Zuweisungsoperator der Basisklasse
 * explizit aufgerufen werden um die geerbten Komponenten zuzuweisen!
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;


class Basis {
 int x;
public:
  Basis(int _x): x(_x) {}

  Basis& operator= (const Basis& b) {
    x=b.x;
    cout << "Basis::operator=(const Basis&)" << endl;
    return *this;
  }

  void info() { cout << x; }
};


class Unter: public Basis {
 int y;
public:
  Unter(int _x, int _y): Basis(_x), y(_y) {}
  Unter& operator= (const Unter& u) { // Zuweisungsoperator der Unterklasse
    Basis::operator=(u);          // !!! Aufruf des Zuweisungsoperators der !!!
                              // !!! Basisklasse muss explizit erfolgen !!!
    y=u.y;                    // Zuweisung Unter-spezifischer Komponenten
    cout << "Unter::operator=(const Unter&)" << endl;
    return *this;
  }
  void info() { Basis::info(); cout << "," << y; }
};


int main() {
  Basis a(1),b(2);
  Unter u(3,4),v(5,6);

  //
  //Zuweisung in der Basisklasse
  cout << "a=";a.info();cout << endl;
  cout << "b=";b.info();cout << endl;
  cout << "Zuweisung a=b in Basis" << endl;
  a=b;
  cout << "Ergebnis: a=";a.info();cout << endl;

  //
  //Zuweisung in der abgeleiteten Klasse
  cout << "u=";u.info();cout << endl;
  cout << "v=";v.info();cout << endl;
  cout << "Zuweisung u=v in Unter" << endl;
  u=v;
  cout << "Ergebnis: u=";u.info();cout << endl;

  //
  //Zuweisung nur der geerbten Komponenten:
  //Methode Basis::operator=(const Basis&) akzeptiert auch Unter-Objekte
  cout <<"Zuweisung b=u:" << endl;
  b=u;
  cout << "Ergebnis: b=";b.info();cout << endl;

  //
  //Zuweisung der Form u=b sinnlos, da
  //1. u Daten (y) enthaelt, die durch b nicht zugewiesen werden koennen
  //2. Aufruf von Unter::operator=(const Unter&) ein Unter-Objekt erwartet

  return 0;
}
