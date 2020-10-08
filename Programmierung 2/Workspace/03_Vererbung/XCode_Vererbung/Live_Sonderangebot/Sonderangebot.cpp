/* 
 * File:   Sonderangebot.cpp
 * Author: henkel
 * 
 * Created on 21. März 2014, 12:31
 */

#include <sstream>
#include "Sonderangebot.h"

Sonderangebot::Sonderangebot()
: Artikel(), sonderpreis(0), angebotsdauer(0) {}

Sonderangebot::Sonderangebot(uint _nr, const string& text, float _preis, uint _lieferzeit,
float _sonderpreis, uint _angebotsdauer)
: Artikel(_nr, text, _preis, _lieferzeit), sonderpreis(_sonderpreis), angebotsdauer(_angebotsdauer) {}

// Kopierkonstruktor:
Sonderangebot::Sonderangebot(const Sonderangebot& orig)
: Artikel(orig), sonderpreis(orig.sonderpreis), angebotsdauer(orig.angebotsdauer) {}

// toString
const string Sonderangebot::toString() {
 ostringstream strom;
 strom << Artikel::toString()
       << ", Sonderpreis " << sonderpreis
       << ", Angebotsdauer " << angebotsdauer;
 return strom.str();
}
