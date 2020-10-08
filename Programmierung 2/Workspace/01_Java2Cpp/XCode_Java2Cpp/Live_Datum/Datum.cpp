/*
 * -----------------------------------------------------------------------------
 * 
 * Liveprojekt: Datum.cpp
 * 
 * Implementation der Klasse Datum und zugehoeriger Funktionen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include "Datum.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;


//
// Konstruktoren und Standardmethoden
Datum::Datum(ushort _tag, ushort _monat, ushort _jahr)
: tag(_tag), monat(_monat), jahr(_jahr) {
 if (!istGueltig()) throw UngueltigesDatum(tag,monat,jahr,__FILE__,__LINE__);
}

Datum::Datum(const string& datumstext) {
  istringstream strom(datumstext);
  char datumspunkt;
  strom >> tag >> datumspunkt >> monat >> datumspunkt >> jahr; 
  if (!istGueltig()) throw UngueltigesDatum(tag,monat,jahr,__FILE__,__LINE__);
}

Datum::Datum(const Datum& _datum) 
: tag(_datum.tag), monat(_datum.monat), jahr(_datum.jahr) {}

Datum& Datum::operator= (const Datum& _datum) {
  tag=_datum.tag;
  monat=_datum.monat;  
  jahr=_datum.jahr;
  return *this;
}

// statische Hilfsfunktion (nur in dieser Datei sichtbar)
static bool teilt(ushort teiler, ushort zahl) {
 return !(zahl%teiler);
}

bool Datum::istSchaltjahr(ushort _jahr) {
 if (teilt(400,_jahr)) return true;
 if ( teilt(4,_jahr) && !teilt(100,_jahr) ) return true;
 return false;
}

/* liefert den letzten Tag im Monat und -1 (bzw. max. ushort-Wert), 
 * falls _monat nicht zwischen 1 und 12 liegt */
ushort Datum::letzterTagImMonat(ushort _monat, ushort _jahr) {
 ushort ergebnis;
 switch (_monat) {
  case 1: ergebnis=31; break;
  case 2: if (istSchaltjahr(_jahr)) ergebnis=29; else ergebnis=28; break;
  case 3: ergebnis=31; break;
  case 4: ergebnis=30; break;
  case 5: ergebnis=31; break;
  case 6: ergebnis=30; break;
  case 7: ergebnis=31; break;
  case 8: ergebnis=31; break;
  case 9: ergebnis=30; break;
  case 10: ergebnis=31; break;
  case 11: ergebnis=30; break;
  case 12: ergebnis=31; break;
 default: ergebnis=-1; // Notiz: ergebnis=Maximaler ushort-Wert! 
 }
 return ergebnis;
}

bool Datum::istGueltig(ushort _tag, ushort _monat, ushort _jahr) {
 bool OK = true;
 OK = ( (1<=_monat) && (_monat<=12) );
 OK = OK && ( (1<=_tag) && (_tag<=letzterTagImMonat(_monat,_jahr)) );
 return OK;
}

bool Datum::klarnameMonat=false;
vector<string> Datum::monatsname={"Januar", "Februar", "Maerz", "April",
"Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember"};

ostream& operator<<(ostream& strom, const Datum& dat) {
 if (Datum::klarnameMonat) {
  strom << dat.gibTag() << ". " 
	  << Datum::monatsname[dat.gibMonat()-1] << " " << dat.gibJahr();
 }
 else {
   strom << dat.gibTag() << '.' << dat.gibMonat() << '.' << dat.gibJahr();
 }
 return strom;
}

/*
 * Einlesen aus einem string und anschliessender Konvertierung mit 
 * Gueltigkeitspruefung. 
 * Diese Art der Initialisierung ist hier zwingend notwendig, da die
 * Operatorfunktion keinen Zugriff auf die privaten Attribute tag, monat, jahr
 * hat und die setter-Methoden bereits eine Gueltigkeitspruefung vornehmen,
 * in der ein vollstaendig initialisiertes Datumsobjekt vorausgesetzt wird
 */
istream& operator>>(istream& strom, Datum& dat) {
 string datumstext;
 strom >> datumstext;
 dat = static_cast<Datum>(datumstext);
                 // ^-- expliziter Typcast notwendig, da Konstruktor
                 //     Datum::Datum(const string&) mittels explicit
                 //     gekennzeichnet 
 return strom;
}

bool Datum::operator ==(const Datum& rhs) const {
 return ( tag==rhs.tag && monat==rhs.monat && jahr==rhs.jahr );
}

bool Datum::operator<(const Datum& rhs ) const {
  // uebersetze Datum in einen Zahlenwert, dessen Groesse ein Mass fuer den
  // Datumswert ist
  unsigned long datumszahl1=tag+monat*31+jahr*31*12;
  unsigned long datumszahl2=rhs.tag+rhs.monat*31+rhs.jahr*31*12;
  // Vergleich der Zahlenwerte leistet das Gewuenschte
  return (datumszahl1<datumszahl2);
}

Datum& Datum::operator ++() {
 if (tag<letzterTagImMonat(monat,jahr))
  ++tag;
 else {
  tag=1;
  if (monat<12) ++monat;
  else {
   monat=1;
   ++jahr;
  }
 }
 return *this;
}

/*
 * Dekrement wirkt nicht am 1.1.0000 
 */
Datum& Datum::operator --() {
 if (tag>1) --tag;
 else {
  if (monat>1) {
   --monat;
   tag=letzterTagImMonat(monat,jahr);
  }
  else {
   if (jahr>0) {
   tag=31;
   monat=12;
   --jahr;
   }
  }
 }
 return *this;
}

 Datum operator++(Datum& dat, int) {
     Datum temp(dat);
     ++dat;
     return temp;
 }
 
 Datum operator--(Datum& dat, int) {
     Datum temp(dat);
     --dat;
     return temp;
 }

 Datum& Datum::operator +=(int tage) {
  if (tage>0) {
   for (int i=0; i<tage; i++) ++(*this);
  }
  if (tage<0) {
   tage=-tage;
   for (int i=0; i<tage; i++) --(*this);
  }
  return *this;
 }
 
 Datum operator+(const Datum& dat, int tage) {
  Datum ergebnis(dat);
  ergebnis+=tage;
  return ergebnis;
 } 
 
 Datum operator-(const Datum& dat, int tage) {
  Datum ergebnis(dat);
  ergebnis-=tage;
  return ergebnis;
 }

 long  operator-(const Datum& ziel, const Datum& start) {
  long zaehler=0;
  Datum zwischen(start);
  while (ziel>zwischen) {
   ++zaehler; ++zwischen;
  }
  while (ziel<zwischen) {
   --zaehler; --zwischen;
  }
  return zaehler;
 }
