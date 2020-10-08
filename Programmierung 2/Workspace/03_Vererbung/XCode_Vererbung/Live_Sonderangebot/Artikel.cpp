/*
 * -----------------------------------------------------------------------------
 *
 * Implementationsdatei: Artikel.cpp
 *
 * Verwendung: In OnlineShop.cpp und Favoriten.cpp
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#include <sstream>
#include "Artikel.h"

Artikel::Artikel()
  : nr(0), beschreibung(""), preis(0.), lieferzeit(0) {}

Artikel::Artikel(uint _nr, const string& text, float _preis, uint _lieferzeit)
  : nr(_nr), beschreibung(text), preis(_preis), lieferzeit(_lieferzeit) {}

const string Artikel::toString() {
  ostringstream strom;
  strom << nr << ": " << beschreibung
        << ", " << preis << "Euro, Lieferzeit "
        << lieferzeit << "Tage";
  return strom.str();
}
