/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: string.cpp
 * 
 * Demonstration zur Verwendung von Strings (Zeichenketten)
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string> //muss eingebunden werden
using namespace std;
int main()
{
    string str{"String"};
    // inhaltlicher Vergleich + Elementzugriff; Ausgabe: r
    if (str == "String")
        cout << str[2] << endl;
    // Konkatenation + Zuweisung
    str += " in c++";
    cout << str.size() << " " << str << endl;
    return 0;
} // Ausgabe: 13 String in C++
