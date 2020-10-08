/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: WarteschlangeP.cpp
 *
 * Demonstration privater Vererbung:
 * Eine Warteschlange als Adapter einer Liste wird mithilfe einer
 * privat vererbten Implementierung der Liste realisiert
 *
 * Quelle: cppbuch/k7/privat/warteschlange.t
 * Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
 * Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#ifndef WARTESCHLANGEP
#define WARTESCHLANGEP
#include<list>


class Warteschlange
  : private std::list<int> { /// mit privater Vererbung
                             /// (Implementationsvererbung)
public:
  using std::list<int>::empty;
  using std::list<int>::size;
  // am Ende einfuegen:
  void push(const int& x)  { std::list<int>::push_back(x);}
  // am Anfang entnehmen:
  void pop()             { std::list<int>::pop_front();}
  // am Anfang bzw. Ende lesen
  using std::list<int>::front;
  using std::list<int>::back;
};


#endif
