/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: Test.cpp
 * 
 * Demonstration Header- und Cpp-Datei
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include "Test.h" // Include-Anweisung der dazugehoerigen Header-Datei;

void f(int i)
{
    cout << "f::" << i << endl;
}

int Test::gib_i()
{ // Implementierung der einzelnen Funktionen;
    return i;
}
