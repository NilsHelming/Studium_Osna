/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: B_U_Komponenten_Namenskonflikte.cpp
 *
 * Ueberdeckung vs Ueberladung bei Vererbung
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;


class Basis {
 public:
  int x;
  void f()      { cout << "Basis::f()" << endl;            }
  void g()      { cout << "Basis::g()" << endl;            }
  void g(int)   { cout << "Basis::g(int)" << endl;         }
  void g(double){ cout << "Basis::g(double)" << endl;      }
};

class Unter: public Basis {
 public:
  int y;
  void g(float) { cout << "Unter::g(float)" << endl;       }
  void h()      { cout << "Unter::h()" << endl;            }
};

class Unter_usingBasis: public Basis {
 public:
  int y;
  using Basis::g; ///ermoeglicht Ueberladung
  void g(float) {cout <<"Unter_usingBasis::g(float)"<<endl;}
  void h()      {cout <<"Unter_usingBasis::h()"<<endl;     }
};

void func(Basis b) {
  cout  << "Betrete Funktion func(Basis)" << endl;
  b.x=1;
  b.f();
  b.g();
  b.g(1);
  b.g(1.5f);
  cout << "Verlasse Funktion func(Basis)" << endl << endl;
}

int main() {
  Basis b;   // Datenkomponente  x; Methoden  f(),g(),g(int),g(double)
  Unter u;   // sichtbare Datenkomponenten x,y; Methoden  f(),g(float),h()

  cout << "Basis b" << endl;
  cout << "-------" << endl;
  b.x=1;
  b.f();
  b.g();
  b.g(1);
  b.g(1.5);
  cout << endl;
 
  cout << "Unter u - Ueberdeckung" << endl;
  cout << "----------------------" << endl;
  u.x=2;
  u.y=3;
  u.f();
  u.Basis::g(); // u.g() gibt es nicht (Ueberdeckung)
  u.g(1.5);     // dasselbe wie:
  u.g(static_cast<float>(1.5));
  u.h();
  cout << endl;

  cout << "Unter u - Upcast" << endl;
  cout << "----------------" << endl;
  func(u);      // enthaelt implizit static_cast<B>(u)

  cout << endl;

  cout << "Unter_usingBasis - Ueberladung" << endl;
  cout << "------------------------------" << endl;
  Unter_usingBasis v;
  v.g();                        // jetzt moeglich
  v.g(1.5);                     // Ueberladung
  v.g(static_cast<float>(1.5)); // Ueberladung


  return 0;
}
