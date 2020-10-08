/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: feld_mit_objekten.cpp
 * 
 * Demonstration der Konstruktoraufrufe bei Vereinbarung von Feldern,
 * deren Komponenten Klassenobjekte sind
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
using namespace std;

// globale Zaehlvariable
int zaehler=0;


/*
 * Klasse, die bei jedem Aufruf eines Konstruktors die zugehoerige
 * Objekt-Komponente nr hochzaehlt
 */
class Komponente {
  int nr;
public:
  Komponente()  : nr(zaehler++)
                      { cout << " K" << nr << endl; }
  Komponente(const Komponente& vk): nr(vk.nr+zaehler++)
                      { cout << "KK" << nr << ' '; }
  ~Komponente() { cout << " D" << nr << ' '; }
};


/*
 * Demonstration der Konstruktoraufrufe bei der Initialisierung
 * eines Feldes und eines Vektors
 */
int main() {
  {
    cout << "Feld mit Komponenten-Objekten" << endl;
    Komponente komponente[5];
    cout << endl;
  }
  cout << endl;
  
  {
    cout << "Vektor mit Komponenten-Objekten" << endl;
    vector<Komponente> komponente(5);
    cout << endl;
  }
  cout << endl;
  
  return 0;
}
