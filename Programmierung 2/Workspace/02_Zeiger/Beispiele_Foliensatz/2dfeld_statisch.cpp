/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: 2dfeld_statisch.cpp
 *
 * statische Erzeugung eines 2d-Feldes (mxn-Matrix)
 * und Demonstration des Zugriffs mittels Zeigerarithmetik
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <iomanip>
using namespace std;

// globale Konstanten
const int M {4};
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
  
  // statische Erzeugung:
  short matrix[M][N];
  //     ^    ^-- mxn-Matrix von short-Werten
  //     |
  //     -- syntaktisch aequivalent zu short (* const matrix)[n]
  //        (so wie ein 1d-Feld syntaktisch aquivalent zu konstantem Zeiger)


  // Mit der Matrix arbeiten...
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      matrix[i][j]=10*i+j;   // also z.B. matrix[2][3]=23
    }
  }

  // Uebergabe an eine Funktion
  gibMatrixAus(matrix,M);

//
//  cout << endl;
//  cout << " matrix:       " <<  matrix << endl
//       << "&matrix[0]:    " << &matrix[0] << endl
//       << " matrix[0]:    " <<  matrix[0] << endl
//       << "&matrix[0][0]: " << &matrix[0][0] << endl;
//  cout << endl;
//
//  //
//  // Zeigerarithmetik auch hier, obwohl die
//  // "Zeiger" matrix[i] nur logisch existieren
//  cout << endl;
//  cout << "Zeigerarithmetik (";
//  cout << "sizeof(short) =" << sizeof(short) << ", "
//       << "sizeof(short*)=" << sizeof(short*) << "):" << endl;
//  cout << "Adresse von matrix[0]    |matrix="
//                                    << matrix << endl;
//  cout << "Adresse von matrix[1]    |matrix+1="
//                                  << matrix+1 << endl;
//  cout << "  (" << N << "*sizeof(short)-Byte-Inkrement)" << endl;
//  cout << "Adresse von matrix[1][0] |*(matrix+1)="
//                                   << *(matrix+1) << endl;
//  cout << "Adresse von matrix[1][1] |*(matrix+1)+1="
//                                   << *(matrix+1)+1 << endl;
//  cout << "  (sizeof(short)-Byte-Inkrement)" << endl;
//  cout << "Wert von matrix[1][1]    |*(*(matrix+1)+1)="
//                                 << *(*(matrix+1)+1) << endl;
//

  //
  // keinen Speicher freigeben (statische Matrix)!

  return 0;
}

