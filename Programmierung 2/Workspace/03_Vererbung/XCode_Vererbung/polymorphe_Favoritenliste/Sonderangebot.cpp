/*
 * -----------------------------------------------------------------------------
 *
 * Implementationsdatei: Sonderangebot.cpp
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#include <sstream>
#include "Sonderangebot.h"

Sonderangebot::Sonderangebot()
: Artikel(), sonderpreis(0), angebotsdauer(0) {}

Sonderangebot::Sonderangebot(uint _nr, const string& _beschreibung,
                             float _preis, uint _lieferzeit,
                             float _sonderpreis, uint _angebotsdauer)
: Artikel(_nr, _beschreibung, _preis, _lieferzeit),
 sonderpreis(_sonderpreis), angebotsdauer(_angebotsdauer) {}

Sonderangebot::Sonderangebot(const Sonderangebot& orig)
: Artikel(orig),
 sonderpreis(orig.sonderpreis), angebotsdauer(orig.angebotsdauer)
{}

Sonderangebot& Sonderangebot::assign(const Artikel& rhs) {
  const Sonderangebot* pS = dynamic_cast<const Sonderangebot*>(&rhs);
  if (!pS) /* Warnmeldung/Ausnahme... */ return *this;
  Artikel::assign(rhs);
  sonderpreis = pS->sonderpreis;
  angebotsdauer = pS->angebotsdauer;
  return *this;
}

const string Sonderangebot::toString(){ 
  ostringstream strom;
  strom<< Artikel::toString();
  strom<<" Sonderangebot fuer "<< angebotsdauer
  <<" Tage, jetzt nur: "<< sonderpreis<<"!";
  
  return strom.str();
  
}


