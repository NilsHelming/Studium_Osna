/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: WarteschlangeD.cpp
 *
 * Demonstration der Delegation:
 * Eine Warteschlange als Adapter einer Liste benutzt eine private Liste
 * und ausgewaehlte Methoden der Liste
 *
 * Quelle: cppbuch/k7/privat/warteschlangeD.t
 * Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
 * Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#ifndef WARTESCHLANGED
#define WARTESCHLANGED
#include<list>


class Warteschlange {
private:                   /// Delegation
  std::list<int> liste;    /// durch privates Listenobjekt
public:
  bool empty( ) { return liste.empty(); }
  size_t size() { return liste.size(); }
  // am Ende einfuegen:
  void push(const int& x)  { liste.push_back(x);}
  // am Anfang entnehmen:
  void pop()             { liste.pop_front();}
  // am Anfang bzw. Ende lesen
  const int& front() { return liste.front();}
  const int& back()  { return liste.back();}
};


#endif
