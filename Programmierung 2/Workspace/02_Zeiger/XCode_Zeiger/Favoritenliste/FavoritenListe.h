/*
 * -----------------------------------------------------------------------------
 *
 * Klassenheader: FavoritenListe.h
 *
 * Verwendung: In Favoriten.cpp
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#ifndef FAVORITENLISTE_H
#define FAVORITENLISTE_H

#include <vector>
#include "Artikel.h"
typedef unsigned int uint;
typedef unsigned long ulong;

class FavoritenListe {
 vector<Artikel*> favorit;   // Artikel werden als Verweise im Vektor
public:                      // gespeichert
 FavoritenListe();
 ~FavoritenListe();
 FavoritenListe(const FavoritenListe& other);
 FavoritenListe& operator=(const FavoritenListe& other);
 
 // getter
 ulong getAnzahl()             { return favorit.size(); }
 Artikel*& operator[](ulong i) { return favorit[i]; }
 //      ^-- Schreibrecht fuer zurueckgebenen Zeiger, falls benoetigt
 
 // Artikel zur Liste hinzufuegen
 FavoritenListe& operator<< (Artikel* art);
};

#endif // FAVORITENLISTE_H
