/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Konto_abstrakt.cpp
 *
 * Anwendungsbeispiel: abstrakte Klasse Konto
 * Diesmal mit virtuellem Destruktor (keine Compilerwarnungen mehr)
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

typedef unsigned int uint;


/*
 * Klassenhierarchie Konto
 */
class Konto {                    // abstrakte Klasse
public:
  virtual void abheben(int) = 0; // rein virtuelle Methode
  virtual ~Konto() {}            // virtueller Destruktor
};

void Konto::abheben(int) {      // Standardimplementation
  cout <<"Konto abheben ";      // (muss es nicht geben)
}


class Sparkonto : public Konto { // konkrete Klasse
public:
  void abheben(int);             // muss es geben, wenn Objekte
};                               // angelegt werden sollen

void Sparkonto::abheben(int) {   // konkrete Implementation
  Konto::abheben(0);
  cout << "vom Sparkonto" << endl;
}


class Girokonto : public Konto { // konkrete Klasse
public:
  void abheben(int);             // muss es geben, wenn Objekte
};                               // angelegt werden sollen

void Girokonto::abheben(int) {   // konkrete Implementation
  Konto::abheben(0);
  cout << "vom Girokonto" << endl;
}
/* Ende Klassenhierarchie Konto     */

/*
 * assoziierte Klasse Bank
 */
class Bank {
  vector<Konto*> konto;                      // Vektor von Basisklassenzeigern
 public:
  Bank();
  ~Bank();
  void transaktionen();
};

Bank::Bank() {
  for (int i=0; i<10; ++i) {
    if(rand()%2)                   // Zeigerziel ist erst zur Laufzeit bekannt
      konto.push_back(new(Sparkonto));
    else
      konto.push_back(new(Girokonto));
  }
}

Bank::~Bank() {
  for (uint i=0; i<konto.size(); ++i) delete konto[i];
}

void Bank::transaktionen() {
  for (uint i=0; i<konto.size(); ++i) {
    konto[i]->abheben(1000);          // Aufruf der virtuellen Methode abheben:
  }                                   //      Es wird die zum Objekt gehoerende
}                                     //             Implementation ausgefuehrt
/* Ende Klasse Bank                 */


/*
 * Demonstration
 */
int main() {
  Bank Bankhaus;
  Konto *k;
  Sparkonto sk;
  Girokonto gk;

  cout << "fruehe Bindung (zur Compilezeit)" << endl;
  sk.abheben(1000);
  gk.abheben(1000);
  cout << endl;

  cout << "spaete Bindung (zur Laufzeit) "
       << "durch Methodenaufruf" << endl;
  cout << "Bankhaus.transaktionen" << endl;
  Bankhaus.transaktionen();
  cout << endl;

  cout << "spaete Bindung (zur Laufzeit) "
       << "durch Benutzereingabe" << endl;
  cout << "Bitte eingeben:" << endl;
  cout << "  1     -- Sparkonto" << endl;
  cout << "  2     -- Girokonto" << endl;
  cout << "  sonst -- Programmende" << endl;
  int wahl;
  cin >> wahl;
  while(wahl==1 or wahl==2) {
    if (wahl==1) k=&sk;
    if (wahl==2) k=&gk;

    k->abheben(1000);                        // spaete Bindung / Polymorphismus1
    cin >> wahl;
  }

  return 0;
}
