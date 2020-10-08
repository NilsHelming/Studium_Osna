/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: OnlineShop.cpp
 *
 * Demonstration von Zeigern als Elemente von Listen (allg. Containern)
 *
 * Ein Onlineshop verwaltet seine Artikel, sowie Listen mit
 * Suchergebnissen von Nutzern (in der Praxis: viele Listen).
 * Die Suchergebnisse sollen intern nach Lieferzeit sortiert werden.
 * Um nicht alle gefundenen Artikel (von saemtlichen Listen) gleichzeitig
 * im Speicher vorhalten zu muessen, werden in den Suchergebnissen nur
 * Verweise (Zeiger) auf die Artikel gespeichert.
 *
 * Nutzen:
 *   Die urspruenglichen Objekte muessen nur einmal im Speicher gehalten
 *   werden
 * Gefahren:
 *   Ueber die Zeiger lassen sich die originalen Objekte veraendern
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <list>
#include <cstdlib>
#include "Artikel.h"
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
 const int anzGesamt=10;          // ein sehr kleiner OnlineShop...
 Artikel alleArtikel[anzGesamt] = {
  Artikel(1,"Scherzkeks", 5.99, 3),
  Artikel(2,"Kruemelmonsters Kekse", 3.99, 4),
  Artikel(3,"Kruemelmonster, klein", 7.99, 1),
  Artikel(4,"\'Junge\', von den Aerzten", 9.99, 2),
  Artikel(5,"Lah-Le-Lu-CD", 12.99, 1),
  Artikel(6,"Quietsche-Entchen", 2.99, 5),
  Artikel(7,"Quietsche-Entchen, Sonderedition rot-metallic", 3.99, 2),
  Artikel(8,"\'Junge\' von Heino", 5.99, 3),
  Artikel(9,"Plagiate leicht gemacht", 10.99, 2),
  Artikel(10,"Ernie-Puppe", 11.99, 1)
 };
 
 
 // zufaellige Suchergebnisse generieren, dabei sollen die
 // Artikel nicht kopiert werden
 cout << "Suchergebnisse:" << endl;
 int anzGefunden=7;               // (Beispiel)
 list<Artikel*> suchergebnisse;   // Liste speichert nur Verweise!
 for (int i=0; i<anzGefunden; i++)
  suchergebnisse.push_back(&alleArtikel[rand()%anzGesamt]);
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
 
 return 0;
}

