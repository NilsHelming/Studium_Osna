/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Favoriten.cpp
 *
 * Demonstration von tiefer Kopie
 *
 * Gespeicherter Artikel werden vom Nutzer lokal in einer
 * Klasse FavoritenListe als Verweise gespeichert.
 * Alle Speichervorgaenge in FavoritenListe sollen tief sein.
 * Die Favoritenliste soll kopiert und zugewiesen werden koennen.
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include "Artikel.h"
#include "FavoritenListe.h"
using namespace std;


int main() {
 // Feld mit Artikeln aufbauen
 const int anzGesamt=10;              // ein sehr kleiner OnlineShop...
 Artikel* alleArtikel[anzGesamt] = {  // Feld von Artikel-Zeigern(!)
  new Artikel(1,"Scherzkeks", 5.99, 3),
  new Artikel(2,"Suesse Schokolade", 3.99, 4),
  new Artikel(3,"Alles wird gut", 7.99, 1),
  new Artikel(4,"\'Junge\', von den Aerzten", 9.99, 2),
  new Artikel(5,"Lah-Le-Lu-CD", 12.99, 1),
  new Artikel(6,"Quietsche-Entchen", 2.99, 5),
  new Artikel(7,"Quietsche-Entchen, Sonderedition rot-metallic", 3.99, 2),
  new Artikel(8,"\'Junge\' von Heino", 5.99, 3),
  new Artikel(9,"Plagiate leicht gemacht", 10.99, 2),
  new Artikel(10,"Ernie-Puppe", 11.99, 1)
 };
 
 
 // Favoritenliste generieren
 int anzFav=4;
 FavoritenListe favListe;
 for (int i=0; i<anzFav; i++)
  favListe << alleArtikel[rand()%anzGesamt];  // Artikel werden kopiert!
 
 // Favoritenliste ausgeben
 cout << "Favoriten:" << endl;
 for (unsigned int i=0; i<favListe.getAnzahl(); i++)
  cout << favListe[i]->toString() << endl;
 cin.get();
 
 // Liste kopieren
 FavoritenListe kopie(favListe);
 cout << endl;
 cout << "Kopie angelegt:" << endl;
 for (unsigned int i=0; i<kopie.getAnzahl(); i++)
  cout << kopie[i]->toString() << endl;
 cin.get();
 
 // Kopie veraendern
 //delete kopie[2];
 //kopie[2]=new Artikel(*(alleArtikel[4]));
 *kopie[2]=*alleArtikel[4];  // ueberschreibt den dereferenzierten Artikel!
 cout << endl;
 cout << "Kopie veraendert:" << endl;
 for (unsigned int i=0; i<kopie.getAnzahl(); i++)
  cout << kopie[i]->toString() << endl;
 
 cout << endl;
 cout << "Original-Liste unveraendert:" << endl;
 for (unsigned int i=0; i<favListe.getAnzahl(); i++)
  cout << favListe[i]->toString() << endl;
 cin.get();
 
 // Zuweisung testen
 cout << endl;
 cout << "Zuweisung:" << endl;
 FavoritenListe favNeu;
 favNeu=favListe;
 for (unsigned int i=0; i<favListe.getAnzahl(); i++)
  cout << favNeu[i]->toString() << endl;
 
 // Selbst-Zuweisung testen:
 // Probehalber Zeile: if (this == &rhs) return *this;
 // in FavoritenListe::operator=() auskommentieren umd
 // Wirkung zu beobachten
 cout << endl;
 cout << "Selbst-Zuweisung:" << endl;
 favNeu=favNeu;
 for (unsigned int i=0; i<favListe.getAnzahl(); i++)
  cout << favNeu[i]->toString() << endl;
 
 // Speicher freigeben
 for (Artikel* artikel: alleArtikel)
  delete artikel;
 // die Artikel in den Favoritenlisten werden
 // in Favoritenliste::~Favoritenliste() geloescht
 
 return 0;
}

