/* 
 * File:   Sonderangebot.h
 * Author: henkel
 *
 * Created on 21. März 2014, 12:31
 */

#ifndef SONDERANGEBOT_H
#define	SONDERANGEBOT_H

#include "Artikel.h"
using namespace std;

class Sonderangebot: public Artikel {
 float sonderpreis;
 uint angebotsdauer;
public:
 Sonderangebot();
 Sonderangebot(uint _nr, const string& text, float _preis, uint _lieferzeit,
               float _sonderpreis, uint _angebotsdauer);
 Sonderangebot(const Sonderangebot& orig);
 
 float gibSonderpreis()   { return sonderpreis; }
 uint  gibangebotsdauer() { return angebotsdauer; }
 void setzeSonderpreis(float sp ) { sonderpreis = sp; }
 void setzeAngebotsdauer(uint ad ) { angebotsdauer = ad; }
 
 const string toString();
 //           ^-- ueberdeckt Artikel::toString
 
};


#endif	/* SONDERANGEBOT_H */

