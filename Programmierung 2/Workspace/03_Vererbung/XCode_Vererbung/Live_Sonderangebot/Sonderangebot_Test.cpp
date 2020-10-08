/*
 * -----------------------------------------------------------------------------
 *
 * Liveprojekt: Sonderangebot
 *
 * Es soll eine von Artikel abgeleitete Klasse Sonderangebot erstellt
 * werden, die zusaetzlich die Daten sonderpreis und angebotsdauer (in Tagen)
 * enthaelt. Sonderangebots-Objekte sollen angelegt, kopiert und mittels
 * einer toString-Methode ausgegeben werden koennen
 *
 * ToDo/Uebungsaufgabe:
 *   Implementieren Sie einen eigenen Zuweisungsoperator in der Klasse
 *   Sonderangebot
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include "Artikel.h"
#include "Sonderangebot.h"
using namespace std;


void ausgabe_als_artikel(Artikel art) {
  cout << art.toString() << endl;
}


int main() {
  
  Artikel normal(3,"Kruemelmonster, klein", 7.99, 1);
  Sonderangebot sonder(8,"\'Junge\' von Heino", 5.99, 3, 2.99, 30);
  Sonderangebot sonderKopie(sonder);
  
  cout << "normal: " << normal.toString() << endl;
  cout << "sonder: "  << sonder.toString() << endl;
  cout << "sonderKopie: "  << sonderKopie.toString() << endl;
  
  cout << "Ausgabe als Artikel:" << endl;
  ausgabe_als_artikel(sonder);
  
  return 0;
}

