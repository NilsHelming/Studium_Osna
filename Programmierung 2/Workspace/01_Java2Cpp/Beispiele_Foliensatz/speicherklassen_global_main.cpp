/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: speicherklassen_global_main.cpp
 * 
 * Demonstration zur Verwendung einer globalen Variable
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

int global = 10; // programmweit globale Variable

void test(int)
{
  global = 1;
}

int main()
{
  cout << "1: g=" << global << endl; // 10
  test(3);
  cout << "2: g=" << global << endl; // 1
  test(7);
  cout << "3: g=" << global << endl; // 1
  test(0);
  cout << "4: g=" << global << endl; // 1
  return 0;
}
