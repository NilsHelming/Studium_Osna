/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: struct.cpp
 * 
 * Demonstration von Daten unterschiedlicher Typen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

struct Person
{ // Person ist jetzt ein neuer Typname;
  string name;
  int alter;
  string adresse;
};
Person person; // person ist eine neue Instanz des Typs Person;

int main()
{
  person.name = "Max Muster";
  person.alter = 30;
  person.adresse = "Hauptstrasse 15";

  cout << person.name << endl
       << person.alter << " Jahre" << endl
       << person.adresse << endl;
  return 0;
}
