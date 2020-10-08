/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: Test.h
 * 
 * Demonstration Header- und Cpp-Datei
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream> // include-Anweisungen zu Beginn der .h-Datei;

using namespace std; // Namensraeume ebenso!

void f(int i); // Funktionsdeklaration außerhalb der Klasse;

class Test
{
    int i{0}; // Init;

public:          // Sichtbarkeitsmodifikator - gilt für alle Funktionen darunter;
    int gib_i(); // Deklarationen der Funktionen von 'Test';
};               // Am Ende der Klassendeklaration muss ein Semikolon stehen;
