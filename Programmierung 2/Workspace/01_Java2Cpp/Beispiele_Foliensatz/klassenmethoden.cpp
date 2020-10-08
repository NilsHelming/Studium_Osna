/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: klassenmethoden.cpp
 * 
 * Demonstration von Klassenmethoden
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include "klassenmethoden.h"

int K::i{1};
void K::methode() { cout << "Ich bin eine statische Methode." << endl; }

int main()
{
    K::methode(); // statischer Aufruf über Bereichsaufloesungsoperator '::'
    return 0;
}
