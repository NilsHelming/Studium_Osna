/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: ganze_zahlen.cpp
 * 
 * Demonstration von Hexadezimalzahlen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

int main()
{
    int hexZahl;

    cin >> hex >> hexZahl;
    // naechste Eingabe wird hexadezimal interpretiert!
    // moegliche Ziffern: 0-9, A-F bzw. a-f
    // Beispieleingabe: c
    cout << hexZahl;
    cout << " (hex: " << hex << hexZahl << ")" << endl;
    // 12 (hex: c)
    return 0;
}
