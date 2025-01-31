/*
 * -----------------------------------------------------------------------------
 *
 * Implementationsdatei: FavoritenListe.cpp
 *
 * Verwendung: In Favoriten.cpp
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#include "FavoritenListe.h"

FavoritenListe::FavoritenListe() {}

FavoritenListe::~FavoritenListe() {  // Speicherfreigabe
 for (int i=0; i<favorit.size(); i++) delete favorit[i];
 favorit.clear();
}

FavoritenListe::FavoritenListe(const FavoritenListe& orig) {
 for (int i=0; i<orig.favorit.size(); i++) // tiefe Kopie
  favorit.push_back(orig.favorit[i]->clone());
}

FavoritenListe& FavoritenListe::operator=(const FavoritenListe& rhs)
{
 if (this == &rhs) return *this;       // Selbstzuweisung verhindern
 
 for (int i=0; i<favorit.size(); i++)  // alten Speicher freigeben
  delete favorit[i];
 favorit.clear();
 
 for (int i=0; i<rhs.favorit.size(); i++) // tiefe Kopie
  favorit.push_back(rhs.favorit[i]->clone());
 
 return *this;                         // dereferenzierter this-Zeiger
}

//
// Artikel zur Liste hinzufuegen
FavoritenListe& FavoritenListe::operator<< (Artikel* art)  {
 favorit.push_back(art->clone());  // tiefes Einspeichern
 
 return *this;                         // dereferenzierter this-Zeiger
}
