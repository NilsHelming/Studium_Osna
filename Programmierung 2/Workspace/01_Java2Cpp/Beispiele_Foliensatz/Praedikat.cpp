/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: Praedikat.cpp
 * 
 * Demonstration zur Verwendung eines Praedikats
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Praedikat, das eine ganze Zahl teiler initialisiert
 * und beim Aufruf mittels des Klammeroperators prueft,
 * ob das uebergebene Argument ein Vielfaches von teiler ist
 */
class IstVielfachesVon
{
  int teiler; // hiervon werden Vielfache gesucht
public:
  IstVielfachesVon(int n) : teiler(n) {} // Konstruktor initialisiert teiler
  bool operator()(int zahl) const
  {                          // prueft, ob zahl Vielfaches
    return !(zahl % teiler); //         von teiler ist
  }
};

/*
 * function count_if
 * zaehlt in einem Vector alle Vielfachen von IstVielfachesVon::teiler
 *
 * in  vec        : const vector<int>&      -- zu durchsuchender Vektor
 * in  vielfach_n : const IstVielfachesVon& -- Praedikat, das die Komponente
 *                                             teiler:int enthaelt
 * return         : size_t                  -- enthaelt die gesuchte Anzahl
 */
size_t count_if(const vector<int> &vec, const IstVielfachesVon &vielfach_n)
{
  size_t anzahl{0}; // bereits initialisiert --^  (!)
  for (size_t i = 0; i < vec.size(); i++)
  {
    if (vielfach_n(vec[i]))
      anzahl++;
    //         ^-- Aufruf von IstVielfachesVon::operator()(int)
  }
  return anzahl;
}

/*
 * function find_if
 * sucht aus einem Vector alle Vielfachen von IstVielfachesVon::teiler
 * heraus und speichert diese in einem neuen Vektor
 *
 * in  vec        : const vector<int>&      -- zu durchsuchender Vektor
 * in  vielfach_n : const IstVielfachesVon& -- Praedikat, das die Komponente
 *                                             teiler:int enthaelt
 * return         : vector<int>             -- enthaelt die Ergebnisse
 */
vector<int> find_if(const vector<int> &vec, const IstVielfachesVon &vielfach_n)
{
  vector<int> ergebnis; // bereits initialisiert --^  (!)
  for (size_t i = 0; i < vec.size(); i++)
  {
    if (vielfach_n(vec[i]))
      ergebnis.push_back(vec[i]);
    //         ^-- Aufruf von IstVielfachesVon::operator()(int)
  }
  return ergebnis;
}

int main()
{
  vector<int> vec{7, -6, 13, 12, 8, 9, 81, -243, 2, 4};
  for (int wert : vec)
    cout << wert << " ";
  cout << endl;
  cout << count_if(vec, IstVielfachesVon(3));
  cout << endl;
  vector<int> neu = find_if(vec, IstVielfachesVon(3));
  for (int wert : neu)
    cout << wert << " ";
  cout << endl;
  return 0;
}
