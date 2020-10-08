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

const string Artikel::toString() {
 ostringstream strom;
 strom << nr << ": " << beschreibung
       << ", " << preis << "Euro, Lieferzeit "
       << lieferzeit << "Tage";
 return strom.str();
}
