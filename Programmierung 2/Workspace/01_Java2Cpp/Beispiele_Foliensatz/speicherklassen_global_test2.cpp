/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: speicherklassen_global_test2.cpp
 * 
 * Demonstration zur Verwendung einer globalen Variable
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

extern int global = 10;  // extern definierte Variable
static int statisch = 1; // modulweit sichtbare Variable
void test(int n)
{
    int statisch = 1;  // statisch jetzt lokal und
    global = statisch; // ueberdeckt den aeusseren Wert
    statisch = n;
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