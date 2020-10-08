/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Iteratoren_Containermethoden.cpp
 *
 * Demonstration zur Verwendung von Iteratoren
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
using namespace std;

// Info-Ausgabe
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
 * Demonstration
 */
int main()
{
  list<int> l = {1, 2, 3, 4}, lKopie(l);
  list<int> ll = {7, 8, 9};
  list<int>::iterator pos, it; // Iteratoren

  cout << endl; // Einfuegen
  cout << "Einfuegen:" << endl;
  info(l);
  pos = l.begin();
  pos++;
  pos++; // Startposition festlegen
  it = l.insert(pos, 6);
  l.insert(it, 5); // Einfuegen von rechts nach links
  info(l);
  l.insert(pos, 7);
  l.insert(pos, 8); // Einfuegen von links nach rechts
  info(l);
  l.insert(pos, 3, -6); // mehrfaches Einfuegen
  info(l);
  pos = l.end(); // Einfuegen einer Liste am Ende
  l.insert(pos, ll.begin(), ll.end());
  info(l);
  cin.get();

  cout << endl; // Entfernen
  cout << "Entfernen:" << endl;
  l = lKopie;
  info(l);
  pos = l.begin();
  pos++; // Startposition festlegen
  it = l.erase(pos);
  info(l); // pos jetzt ungueltig
  it = l.erase(it, l.end());
  info(l); // Loeschen bis zum Listenende
  cout << boolalpha << (it == l.end()) << endl;
  cin.get();

  cout << endl; // Einsetzen
  cout << "Einsetzen:" << endl;
  l = lKopie;
  cout << "l:  ";
  info(l);
  cout << "ll: ";
  info(ll);
  pos = l.begin();
  pos++;
  pos++;             // Startposition festlegen
  l.splice(pos, ll); // ll vor pos einsetzen
  cout << "l:  ";
  info(l);
  cout << "ll: ";
  info(ll);

  return 0;
}
