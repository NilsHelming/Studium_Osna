/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: Typumwandlung_Gefahren1.cpp
 * 
 * zeigt, wie man unbeabsichtigte Umwandlungen verhindern kann
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

/* 
 * Klasse mit Typumwandlung durch den Konstruktor
 */
class X
{
public:
  /*explicit*/ // verhindert:
  X(int)       // Benutzerdefinierte Konversion von int nach X
  {
    cout << "XK" << endl;
  } // mittels Konstruktor
  ~X() { cout << "XD" << endl; }
};

/*
 * Eine Funktion auf (namenlosen) Objekten der Klasse X
 */
void f(X)
{
  cout << "f aufgerufen" << endl;
}

/*
 * Demo
 */
int main()
{

  f(11); // Konversion von int nach X mittels X(int)
  f(static_cast<X>(11));

  f(0.5);                 // Standardkonvertierung double nach int und
  f(static_cast<X>(0.5)); // Konversion von int nach X mittels X(int)
}
