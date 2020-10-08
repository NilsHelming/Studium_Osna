/*
 * -----------------------------------------------------------------------------
 *
 * Liveprojekt: OnlineShop_polymorph
 * 
 * Das OnlineShop-Bsp aus Kapitel Zeiger
 * vorgenommene Aenderungen sind mit "// !!!" kommentiert
 *
 * ToDo/Uebungsaufgabe:
 *   Aendern Sie die vorhandene Implementation so ab, dass sie sowohl
 *   mit Artikel- als auch mit Sonderangebot-Objekten funktioniert
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <list>
#include <cstdlib>
#include "Artikel.h"
#include "Sonderangebot.h"
using namespace std;


// binaeres Praedikat zum Vergleich zweier
// Artikel-Zeiger
class LieferzeitKleiner {
public:
  bool operator()(Artikel* links, Artikel* rechts)
  { return links->gibLieferzeit() < (*rechts).gibLieferzeit();
    //          ^-- Abkuerzung fuer --^
  }
};


int main() {

  // Feld mit Artikeln aufbauen
  // !!!
  // !!! Achtung: Feld enthaelt jetzt (Basisklassen-)Zeiger
  // !!!
  const int anzGesamt=10;              // ein sehr kleiner OnlineShop...
  Artikel* alleArtikel[anzGesamt] = {
    new Artikel(1,"Scherzkeks", 5.99, 3),
    new Artikel(2,"Kruemelmonsters Kekse", 3.99, 4),
    new Artikel(3,"Kruemelmonster, klein", 7.99, 1),
    new Artikel(4,"\'Junge\', von den Aerzten", 9.99, 2),
    new Artikel(5,"Lah-Le-Lu-CD", 12.99, 1),
    new Artikel(6,"Quietsche-Entchen", 2.99, 5),
    new Sonderangebot(7,"Quietsche-Entchen, Sonderedition rot-metallic", 3.99, 2, 3.49, 5),
    new Sonderangebot(8,"\'Junge\' von Heino", 5.99, 3, 2.99, 30),
    new Sonderangebot(9,"Plagiate leicht gemacht", 10.99, 2, 6.99, 14),
    new Artikel(10,"Ernie-Puppe", 11.99, 1)
  };


  // zufaellige Suchergebnisse generieren, dabei sollen die
  // Artikel nicht kopiert werden
  cout << "Suchergebnisse:" << endl;
  int anzGefunden=7;               // (Beispiel)
  list<Artikel*> suchergebnisse;   // Liste speichert nur Verweise!
  for (int i=0; i<anzGefunden; i++)
    suchergebnisse.push_back(alleArtikel[rand()%anzGesamt]); // !!!
                         //  ^-- Speicheradresse des Artikels

  // Ausgabe der Suchergebnisse
  list<Artikel*>::iterator it;  // "Zeiger" auf Listenelemente
  for (it=suchergebnisse.begin(); it!=suchergebnisse.end(); it++)
    cout << (*(*it)).toString() << endl;
    //       ^ ^-- Elementzugriff im Container mittels Iterator
    //       |     Ergebnis ist vom Typ Artikel*
    //       |
    //       -- Dereferenziert den Zeiger;
    //          Ergebnis ist vom Typ Artikel


  // Sortieren der Ergebnisliste
  // --> Es werden nur die Zeiger sortiert, nicht die
  //     Artikelobjekte selbst!
  cout << endl << "Nach Lieferzeit sortiert:" << endl;
  suchergebnisse.sort(LieferzeitKleiner());
  for (it=suchergebnisse.begin(); it!=suchergebnisse.end(); it++)
    cout << (*it)->toString() << endl;
    //       ^   ^-- auch bei Zeigern gibt es
    //       |       die Komponentenselektion mittels ->
    //       -- Beachte: *it hat den Typ Artikel*
    //          Artikel* ist ein Zeiger, kein Klassenobjekt,
    //          daher ist it-> hier syntaktisch falsch

  for (int i=0; i<anzGesamt; i++) delete alleArtikel[i]; // !!!
  return 0;
}

