/*
 * -----------------------------------------------------------------------------
 *
 * Klassenheader: Sonderangebot.h
 *
 * Ableitung von Artikel mit zusaetzlichen Attributen
 * sonderpreis und angebotsdauer, sowie einer ueberladenen Methode
 * toString
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#ifndef SONDERANGEBOT_H
#define	SONDERANGEBOT_H

using namespace std;
#include "Artikel.h"

class Sonderangebot : public Artikel {
  float sonderpreis;
  uint angebotsdauer;
public:
  Sonderangebot();
  Sonderangebot(uint, const string&, float, uint, float, uint);
  Sonderangebot(const Sonderangebot& orig);
  float gibSonderpreis(){return sonderpreis;}
  uint gibAngebotsdauer(){return angebotsdauer;}
  void setzeSonderpreis(float _sonderpreis){sonderpreis=_sonderpreis;}
  void setzeAngebotsdauer(uint _angebotsdauer){angebotsdauer=_angebotsdauer;}
  const string toString();
};

#endif	/* SONDERANGEBOT_H */

