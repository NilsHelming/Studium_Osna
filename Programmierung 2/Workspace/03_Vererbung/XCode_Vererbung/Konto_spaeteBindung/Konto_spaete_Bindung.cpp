/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Konto_spaete_Bindung.cpp
 *
 * Polymorphismus am Beispiel verschiedener Bankkonten, die von einer
 * zentrale Basisklasse abgeleitet sind.
 *
 * Vorsicht: ggf. Compilerwarnungen
 * (werden in der nachfolgenden Version --> Konto_abstrakt
 *  eliminiert)
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
class Konto {
public:
  virtual void abheben(int)         // virtual kennzeichnet eine Methode als
  { cout <<"Konto abheben"<< endl; }// ueberschreibbar in abgeleiteten Klassen
};


class Sparkonto : public Konto {
public:
  void abheben(int)                 // hier
  { cout << "Sparkonto abheben" << endl; }
};

class Girokonto : public Konto {
public:
  void abheben(int)                 // und hier
  { cout << "Girokonto abheben" << endl; }
};
/* Ende Klassenhierarchie Konto     */


/*
 * assoziierte Klasse Bank
 */
class Bank {
  vector<Konto*> konto;             // Vektor von Basisklassenzeigern
 public:
  Bank();
  ~Bank();
  void transaktionen();
};

Bank::Bank() {
  for (int i=0; i<10; ++i) {
    if(rand()%2)                    // Zeigerziel ist erst zur Laufzeit bekannt
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
    konto[i]->abheben(1000);        // Aufruf der virtuellen Methode abheben:
  }                                 // Es wird die zum Objekt gehoerende
}                                   // Implementation ausgefuehrt
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

    k->abheben(1000);    /// spaete Bindung / Polymorphismus
    cin >> wahl;
  }


  return 0;
}
