/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: klassenmethoden.h
 * 
 * Demonstration von Klassenmethoden
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

class K
{
    static int i;
    // static inline int j {1};
    static const int k;
    static const int l{1};
    static int field[l];

public:
    static void methode();
};
