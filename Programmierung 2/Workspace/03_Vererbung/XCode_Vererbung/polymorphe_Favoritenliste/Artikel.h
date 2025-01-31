/*
 * -----------------------------------------------------------------------------
 *
 * Klassenheader: Artikel.h
 *
 * Verwendung: In OnlineShop.cpp und Favoriten.cpp
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#ifndef ARTIKEL_H
#define ARTIKEL_H

#include <string>
using namespace std;
typedef unsigned int uint;

class Artikel {
private:
 uint nr {0};
 string beschreibung {""};
 float preis {0.};
 uint lieferzeit {0};
public:
 Artikel() {}
 Artikel(uint _nr, const string& text, float _preis, uint _lieferzeit)
  : nr(_nr), beschreibung(text), preis(_preis), lieferzeit(_lieferzeit) {}
 
 virtual Artikel* clone() const { return new Artikel(*this); }
 Artikel& operator=(const Artikel& rhs)
 { if (this==&rhs) return *this; return assign(rhs); }
 virtual Artikel& assign(const Artikel& rhs);
 
 unsigned int gibNr()                          { return nr; }
 void setzeNr(unsigned int val)                 { nr = val; }
 string gibBeschreibung()            { return beschreibung; }
 void setzeBeschreibung(string val)   { beschreibung = val; }
 float gibPreis()                           { return preis; }
 void setzePreis(float val)                  { preis = val; }
 unsigned int gibLieferzeit()          { return lieferzeit; }
 void setzeLieferzeit(unsigned int val) { lieferzeit = val; }
 
 virtual const string toString();
 virtual ~Artikel() {}
};

#endif // ARTIKEL_H
