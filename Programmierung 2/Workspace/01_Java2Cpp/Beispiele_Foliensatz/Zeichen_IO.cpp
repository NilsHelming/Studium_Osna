/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: Zeichen_IO.cpp
 *
 * Demonstration zur Manipulation von Zeicheneingaben
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <iomanip> ///Manipulatoren
using namespace std;

int main()
{
  char buchstabe;
  cin >> buchstabe;
  cout << ((buchstabe >= 'A') && (buchstabe <= 'Z'));
  // true, falls Grossbuchstabe

  cout << setw(10) << setfill('.') << "Hallo" << endl;
  // .....Hallo
  cout << left << setw(10) << setfill('_') << "Hallo" << endl;
  // Hallo_____

  return 0;
}