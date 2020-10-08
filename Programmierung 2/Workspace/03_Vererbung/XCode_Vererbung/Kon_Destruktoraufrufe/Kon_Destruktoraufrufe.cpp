/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Kon_Destruktoraufrufe.cpp
 *
 * Konstruktoren und Destruktoren in Basis- und abgeleiteten Klassen
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;


class Basis {
public:
  Basis()       { cout << "Basis()"       << endl; }
  Basis(int)    { cout << "Basis(int)"    << endl; }
  Basis(Basis&) { cout << "Basis(Basis&)" << endl; }
  ~Basis()      { cout << "~Basis()"      << endl; }
};


class Unter_default: public Basis {
public:
  Unter_default()               { cout << "Unter_default()"       << endl; }
  Unter_default(int)            { cout << "Unter_default(int)"    << endl; }
  Unter_default(Unter_default&) { cout << "Unter_default(Unter_default&)" << endl; }
  ~Unter_default()              { cout << "~Unter_default()"      << endl; }
};


class Unter_passend: public Basis {
public:
  Unter_passend():Basis()             { cout << "Unter_passend()"       << endl; }
  Unter_passend(int):Basis(0)         { cout << "Unter_passend(int)"    << endl; }
  Unter_passend(Unter_passend&u):Basis(u) { cout << "Unter_passend(Unter_passend&)" << endl; }
  ~Unter_passend()                    { cout << "~Unter_passend()"      << endl; }
};


int main() {
  cout << "Unter_default: kein expliziter Konstruktoraufruf der Basisklasse"
       << endl;
  Unter_default default1,default2(0),default3(default2);
  cout << endl;


  cout << "Unter_passend: Aufruf des passenden Konstruktors der Basisklasse"
       << endl;
  Unter_passend passend1,passend2(0),passend3(passend2);
  cout << endl;


  cout << "Aufruf der Destruktoren..." << endl;
}
