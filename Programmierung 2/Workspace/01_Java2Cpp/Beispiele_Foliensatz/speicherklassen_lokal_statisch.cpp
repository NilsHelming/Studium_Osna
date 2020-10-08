/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: speicherklassen_lokal_statisch.cpp
 * 
 * Demonstration zur Verwendung einer statischen Variable
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;
int test()
{
  static int i = 1; // wird beim Programmstart
                    // EINMALIG initialisiert
  return i++;
} // i ueberlebt das Ende der Verbundanweisung

int main()
{
  cout << test() << endl; // 1
  cout << test() << endl; // 2
  cout << test() << endl; // 3
  //cout << i << endl;    // i hier unbekannt
  return 0;
}
