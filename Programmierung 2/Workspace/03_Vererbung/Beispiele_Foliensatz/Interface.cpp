/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Interface.cpp
 *
 * Skizze zur Definition einer Interface-Klasse
 * und zugehoeriger Implementation durch eine abgeleitete Klasse
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include<iostream>
using namespace std;


// Interface --- abstrakte Klasse mit 100% rein virtuellen Methoden ohne Daten
class IstVergleichbar {
public:
  virtual bool operator<(const IstVergleichbar&) const = 0;
  virtual ~IstVergleichbar() = 0;
};


// Implementierende Klasse
class MeineDaten : public IstVergleichbar {
  /* private Daten und Methoden */
public:
  bool operator<(const IstVergleichbar& rhs) const {
    const MeineDaten* pMeineDaten=dynamic_cast<const MeineDaten*>(&rhs);
    if (!pMeineDaten) { /* Werfe Ausnahme */ }
    /* Jetzt den Vergleich implementieren */
  }
};
