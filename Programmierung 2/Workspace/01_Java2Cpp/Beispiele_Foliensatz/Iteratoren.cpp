/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Iteratoren.cpp
 *
 * Demonstration zur Verwendung von Iteratoren
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <list>
using namespace std;

// Eine Klasse, die nichts macht
class EgalWas
{
public:
  int x;
  int y;
  EgalWas(int _x, int _y) : x(_x), y(_y) {}
};

/*
 * Demonstration
 */
int main()
{
  // Initialisierung mit Sequenzkonstruktor
  vector<int> v = {1, 2, 3, 3, 3, 2, 4, -4};
  // Initialisierung mit Iteratorsequenz
  list<int> l(v.begin(), v.end());

  cout << endl; // Bidirektionale Iteratoren fuer Listen
  // Positionierung und Elementzugriff
  list<int>::iterator it; // Iteratoren fuer list<int>-Objekte
  list<int>::reverse_iterator r_it;

  for (it = l.begin(); it != l.end(); it++)
    cout << *it << " ";
  cout << endl;
  for (r_it = l.rbegin(); r_it != l.rend(); r_it++)
    cout << *r_it << " ";
  cout << endl;

  cout << endl; // Random-Access Iteratoren fuer Vektoren
  vector<int>::iterator v_iter = v.begin();
  v_iter += 5;
  cout << *v_iter << " " << v_iter[1] << " ";
  cout << boolalpha << (v_iter < v.end()) << endl;

  cout << endl; // Zugriff auf Klassenkomponenten
  EgalWas egal(1, 2), ganzEgal(3, 4), totalEgal(5, 6);
  vector<EgalWas> vec_egal = {egal, ganzEgal, totalEgal};
  vector<EgalWas>::iterator it_egal = vec_egal.begin();
  for (size_t i = 0; i < vec_egal.size(); i++)
    cout << it_egal[i].x << "," << (it_egal + i)->y << " ";
  //             ^-- greift direkt auf   ^-- zeigt auf das i-te Element
  //                 i-tes Element zu        -> greift darauf zu und selektiert
  //                 und selektiert davon       dessen y-Komponente
  //                 die x-Komponente
  cout << endl;

  return 0;
}
