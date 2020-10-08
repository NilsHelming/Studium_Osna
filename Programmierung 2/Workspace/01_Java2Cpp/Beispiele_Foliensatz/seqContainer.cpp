/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: seqContainer.cpp
 *
 * Demonstration einiger Operationen an den sequentiellen Containern
 * vector, deque und list
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <iterator>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
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
     cout << " front=" << c.front()
          << " back=" << c.back()
          << endl;
}

/*
 * Demonstration
 */
int main()
{
     // Container erzeugen
     vector<int> v, vv;
     deque<int> dq, dqq;
     list<int> l, ll;

     cout << boolalpha; // boolsche Werte als Text ausgeben

     // Vektoren
     cout << "--------" << endl
          << "Vektoren" << endl
          << "--------" << endl;
     v.push_back(1);
     v.push_back(2);
     v.push_back(3);
     v.push_back(0);
     cout << "vector v : ";
     info(v);
     vv = v;
     cout << "v==vv: " << (v == vv) << endl;
     vv.pop_back();
     cout << "vv.pop.back()..." << endl;
     cout << "vector vv: ";
     info(vv);
     cout << "v<vv? " << (v < vv) << endl;
     cin.get();
     // Schlangen
     cout << "--------" << endl
          << "Schlange" << endl
          << "--------" << endl;
     dq.push_back(1);
     dq.push_back(2);
     dq.push_back(3);
     dq.push_front(0);
     cout << "deque dq : ";
     info(dq);
     dqq = dq;
     cout << "dq==dqq: " << (dq == dqq) << endl;
     dqq.pop_front();
     cout << "dqq.pop_front()..." << endl;
     cout << "deque dqq: ";
     info(dqq);
     cout << "dq<dqq? " << (dq < dqq) << endl;
     cin.get();
     // Listen
     cout << "------" << endl
          << "Listen" << endl
          << "------" << endl;
     l.push_back(1);
     l.push_back(2);
     l.push_back(3);
     l.push_front(0);
     cout << "list l : ";
     info(l);
     ll = l;
     cout << "l==ll: " << (l == ll) << endl;
     ll.pop_front();
     cout << "ll.pop_front()..." << endl;
     cout << "list ll: ";
     info(ll);
     cout << "l<ll? " << (l < ll) << endl;

     return 0;
}
