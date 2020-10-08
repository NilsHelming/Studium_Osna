/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: 2dfeld_variableZeilen.cpp
 *
 * dynamische Erzeugung einer 2d-Tabellenstruktur fuer zur Laufzeit
 * und Demonstration des Zugriffs mittels Zeigerarithmetik
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <iomanip>
using namespace std;


void gibTabelleAus(short** tabelle, int m,   int* n) {
                 //       ^--Tabelle   ^--Zeilen ^--Spalten
  cout << endl;
  for (int i=0; i<m; i++) {
    cout << n[i] << "| ";
    for (int j=0; j<n[i]; j++) {
      cout << setw(2) << setfill('0') << tabelle[i][j] << " ";
    }
    cout << endl;
  }
}


int main() {

  // Dimensionierungen, ggf. erst zur Laufzeit bekannt
  // z.B. durch Benutzereingabe im laufenden Programm
  int m=4;              // Anzahl Zeilen
  int *n=new int[m];    // Zur Aufnahme der
  n[0]=3; n[1]=5; n[2]=4; n[3]=6; //        Zeilenlaengen

  // dynamische Erzeugung: 1. Schritt
  short **const tabelle=new short*[m];
          // new legt Speicher fuer Feld aus m short-Zeigern
          // an liefert einen Zeiger darauf zurueck

  // dynamische Erzeugung: 2. Schritt
  for(int i=0;i<m;i++)  // Fuer jeden short-Zeiger ein Feld
    tabelle[i]=new short[n[i]]; // variabler Laenge
                              // fuer short-Werte erzeugen

  // Mit der Tabelle arbeiten...
  for (int i=0; i<m; i++) {
    for (int j=0; j<n[i]; j++) {
      tabelle[i][j]=10*i+j;   // also z.B. tabelle[2][3]=23
    }
  }

  // Uebergabe an eine Funktion
  gibTabelleAus(tabelle,m,n);

  cout << endl;
  cout << " tabelle        " <<  tabelle << endl
       << "&tabelle[0]:    " << &tabelle[0] << endl
       << " tabelle[0]:    " <<  tabelle[0] << endl
       << "&tabelle[0][0]: " << &tabelle[0][0] << endl;
  cout << endl;

  //
  // Zeigerarithmetik
  cout << endl;
  cout << "Zeigerarithmetik (";
  cout << "sizeof(short) =" << sizeof(short) << ", "
       << "sizeof(short*)=" << sizeof(short*) << "):" << endl;
  cout << "Adresse von tabelle[0]    |tabelle="
                                    << tabelle << endl;
  cout << "Adresse von tabelle[1]    |tabelle+1="
                                  << tabelle+1 << endl;
  cout << "  (sizeof(short*)-Byte-Inkrement)" << endl;
  cout << "Adresse von tabelle[1][0] |*(tabelle+1)="
                                   << *(tabelle+1) << endl;
  cout << "Adresse von tabelle[1][1] |*(tabelle+1)+1="
                                   << *(tabelle+1)+1 << endl;
  cout << "  (sizeof(short)-Byte-Inkrement)" << endl;
  cout << "Wert von tabelle[1][1]    |*(*(tabelle+1)+1)="
                                 << *(*(tabelle+1)+1) << endl;

  //
  // Speicher wieder freigeben in UMGEKEHRTER Reihenfolge
  for(int i=0;i<m;i++) delete[] tabelle[i];//erst die short-Felder
  delete[] tabelle;                        //dann das Zeigerfeld
  delete[] n;                              //schliesslich: Zeilenlaengen
 
  return 0;
}

