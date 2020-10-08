/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: 2dfeld_dynamisch.cpp
 *
 * dynamische Erzeugung eines 2d-Feldes (mxn-Matrix) zur Laufzeit
 * und Demonstration des Zugriffs mittels Zeigerarithmetik
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <iomanip>
using namespace std;

// globale Konstante
const int N {3};

void gibMatrixAus(short (*pFeld)[N],  int m) {
               //       ^               ^--Zeilen
               //       |
               //       -- Zeiger auf ein Feld mit N Elementen (Spalten)
  cout << endl;
  for (int i=0; i<m; i++) {
    cout << N << "| ";
    for (int j=0; j<N; j++) {
      cout << setw(2) << setfill('0') << pFeld[i][j] << " ";
    }
    cout << endl;
  }
}


int main() {

  // Dimensionierung der Zeilen, ggf. erst zur Laufzeit bekannt
  // z.B. durch Benutzereingabe im laufenden Programm
  int m=4;              // Anzahl Zeilen

  // dynamische Erzeugung:
  short (*const pMatrix)[N] = new short[m][N];
       //       ^                 ^-- mxn-Matrix von short-Werten
       //       |
       //       -- konstanter Zeiger auf ein Feld von n short-Werten
       //          Beachte: Die Spaltendimension n gehoert zur Typangabe!


  // Mit der Matrix arbeiten...
  for (int i=0; i<m; i++) {
    for (int j=0; j<N; j++) {
      pMatrix[i][j]=10*i+j;   // also z.B. pMatrix[2][3]=23
    }
  }


  // Uebergabe an eine Funktion
  gibMatrixAus(pMatrix,m);

//  cout << endl;
//  cout << " pMatrix:       " << pMatrix << endl
//       << "&pMatrix[0]:    " << &pMatrix[0] << endl
//       << " pMatrix[0]:    " <<  pMatrix[0] << endl
//       << "&pMatrix[0][0]: " << &pMatrix[0][0] << endl;
//  cout << endl;
//
//  //
//  // Zeigerarithmetik
//  cout << endl;
//  cout << "Zeigerarithmetik (";
//  cout << "sizeof(short) =" << sizeof(short) << ", "
//       << "sizeof(short*)=" << sizeof(short*) << "):" << endl;
//  cout << "Adresse von pMatrix[0]    |pMatrix="
//                                    << pMatrix << endl;
//  cout << "Adresse von pMatrix[1]    |pMatrix+1="
//                                  << pMatrix+1 << endl;
//  cout << "  (" << N << "*sizeof(short)-Byte-Inkrement)" << endl;
//  cout << "Adresse von pMatrix[1][0] |*(pMatrix+1)="
//                                   << *(pMatrix+1) << endl;
//  cout << "Adresse von pMatrix[1][1] |*(pMatrix+1)+1="
//                                   << *(pMatrix+1)+1 << endl;
//  cout << "  (sizeof(short)-Byte-Inkrement)" << endl;
//  cout << "Wert von pMatrix[1][1]    |*(*(pMatrix+1)+1)="
//                                 << *(*(pMatrix+1)+1) << endl;

  //
  // Speicher wieder freigeben
  delete[] pMatrix;     // ganze Matrix wird jetzt freigegeben

  return 0;
}

