/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Listenmanipulation.cpp
 *
 * Demonstration einiger speziell fuer Listen existierender Methoden
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <iterator>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// Hilfsfunktion
//   verwendete Sprachelemente --> spaeter
template <typename Container>
void info(const Container &c)
{
  cout << c.size() << "| ";
  copy(c.begin(), c.end(), ostream_iterator<typename Container::value_type>(cout, " "));
  cout << "|" << endl;
  // cout << " front=" << c.front()
  //      << " back="  << c.back()
  //      << endl;
}

/*
 * (unaeres) Praedikat fuer Listenelemente
 * - wahr, wenn Wert des Listenelementes gleich 1 ist
 * - falsch, sonst
 */
class IstEins
{
public:
  bool operator()(int n) { return (n == 1); }
};

/*
 * binaeres Praedikat zum Abgleich von Listenelementen
 */
class IstBetragsGleich
{
public:
  bool operator()(int i, int j) { return (abs(i) == abs(j)); }
};

/*
 * binaeres Praedikat zum Vergleich von Listenelementen
 */
class BetragKleiner
{
public:
  bool operator()(int i, int j) { return (abs(i) < abs(j)); }
};

/*
 * Demonstration
 */
int main()
{
  list<int> l = {1, 2, 3, 3, 3, 2, 4, -4};
  info(l);

  cout << endl;
  //  Demo von Methode unique
  list<int> ll(l);
  ll.unique(); // entfernt benachbarte Doppelte
  cout << "unique():                   ";
  info(ll);
  ll.unique(IstBetragsGleich()); // entfernt benachbarte "gleiche" Doppelte
  cout << "unique(IstBetragsGleich()): ";
  info(ll);
  cin.get();

  cout << endl;
  // Demo von Methode remove
  ll = l;
  ll.remove(2); // entfernt alle Elemente mit gegebenen Wert
  cout << "remove(2):          ";
  info(ll);
  ll.remove_if(IstEins()); // entfernt alle Elemente, fuer die das Praedikat
  cout << "remove_if(IstEins()):";
  info(ll); // true liefert
  cin.get();

  cout << endl;
  // Demo von Methode sort
  ll = l;
  ll.sort();
  cout << "sort():                ";
  info(ll);
  ll.sort(BetragKleiner());
  cout << "sort(BetragKleiner()): ";
  info(ll);
  cin.get();

  cout << endl;
  // Demo von Methode merge
  // ll.merge(zweiteListe,cmp) fuegt aktuelles Element el2 von zweiteListe
  // vor aktuellem Element el1 von ll ein, falls cmp(el2,el1) wahr ist.
  // zweiteListe ist danach leer
  ll = l;
  list<int> zweiteListe = {2, 1, -3, 5};
  list<int> sicherungskopie(zweiteListe);
  // Vorher:
  cout << "alteListe:               ";
  info(ll);
  cout << "zweiteListe:             ";
  info(zweiteListe);
  ll.merge(zweiteListe);
  //  Nach merge()
  cout << "merge():                ";
  info(ll);
  cin.get();

  ll = l;
  zweiteListe = sicherungskopie;
  ll.merge(zweiteListe, BetragKleiner());
  // Nach merge(BetragKleiner())
  cout << "merge(BetragKleiner()): ";
  info(ll);
  cout << "zweiteListe              ";
  info(zweiteListe);

  return 0;
}
