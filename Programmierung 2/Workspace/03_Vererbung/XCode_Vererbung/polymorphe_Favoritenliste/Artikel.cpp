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

Artikel& Artikel::assign(const Artikel& rhs) {
 nr = rhs.nr;
 beschreibung = rhs.beschreibung;
 preis = rhs.preis;
 lieferzeit = rhs.lieferzeit;
 return *this;
}

const string Artikel::toString() {
 ostringstream strom;
 strom << nr << ": " << beschreibung
       << ", " << preis << "Euro, Lieferzeit "
       << lieferzeit << "Tage";
 return strom.str();
}
