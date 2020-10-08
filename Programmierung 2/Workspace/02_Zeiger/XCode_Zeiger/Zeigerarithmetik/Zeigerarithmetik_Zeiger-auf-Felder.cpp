/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: zeigerarithmetik_felder.cpp
 *
 * Anzeige des Speicherabbildes und Zugriffsmoeglichkeiten fuer Felder 
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

int main() {
  const int n=3;
  //
  short feld[n] = {1,2,3};   // Feld von n short-Werten
  short *pf = feld;          // Zeiger auf ersten short-Wert in feld
  short (*pfeld)[n] = &feld; // Zeiger auf ein feld
  //
  short *pFeld[n] = {pf, pf+1, pf+2};  // Feld von short-Zeigern
  short **pF = pFeld;        // Zeiger auf ersten short-Zeiger in pFeld
  
  
  // Elemente in feld
  cout << "Werte: ";
  cout << feld[0] << " "
  << *(pf+1) << " "
  << (*pfeld)[2] << endl; // Klammern!
  
  // Elementadressierung in feld
  cout << "Adressen:" << endl;
  cout << " ";
  for (int i=0; i<85; i++) cout << "_";
  for (int i=0; i<27; i++) cout << ".";
  cout << endl;
  
  for(int i=0; i<n; i++)
    cout << " |     feld+" << i << " " << feld+i;
  cout << " |" << endl;
  for(int i=0; i<n; i++)
    cout << " |       pf+" << i << " " << pf+i;
  cout << " |" << endl;
  for(int i=0; i<n; i++)
    cout << " | *(pfeld)+" << i << " " << (*pfeld)+i;
  cout << " |" << endl;
  
  cout << " |      pfeld " << pfeld
  << " |                           |                           |"
  << "   pfeld+1 " << pfeld+1 << endl;
  
  cout << " ";
  for (int i=0; i<85; i++) cout << "-";
  for (int i=0; i<28; i++) cout << ".";
  cout << endl;
  
  cout << endl;
  
  // indirekte Elementadressierung durch Verweise
  //
  // Werte in pFeld
  cout << "Werte: ";
  cout << pFeld[0] << " ";
  cout << *(pFeld+1) << " ";
  cout << *(pF+2) << endl;
  
  // Dereferenzierte Werte in pFeld
  cout << "Dereferenzierte Werte: ";
  cout << *(pFeld[0]) << " ";
  cout << *( *(pFeld+1) ) << " ";
  cout << *( *(pF+2) ) << endl;
  
  // Adressen in pFeld
  cout << "Adressen:" << endl;
  cout << " ";
  for (int i=0; i<85; i++) cout << "-";
  cout << endl;
  
  for(int i=0; i<n; i++)
    cout << " |    pFeld+" << i << " " << pFeld+i;
  cout << " |" << endl;
  for(int i=0; i<n; i++)
    cout << " |       pF+" << i << " " << (pF+i);
  cout << " |" << endl;
  cout << " ";
  
  for (int i=0; i<85; i++) cout << "-";
  cout << endl;
  
  cout << endl;
  return 0;
}

