/*
 * -----------------------------------------------------------------------------
 * 
 * Uebung: uebung_person.cpp
 * 
 * Uebung mit Kon-/Destruktoren
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>

using namespace std;

class Person
{
    string name, adresse;

public:
    Person() { cout << "Person" << endl; }               // Standardkonstruktor
    Person(Person &p) : name(p.name), adresse(p.adresse) // Kopierkonstruktor - Initialisiere 'name' und 'adresse'
    {
        cout << "Person--Init" << endl;
    }
    ~Person() { cout << "~Person" << endl; } // Destruktor
};

class Student
{
    Person person; // Instanz der Klasse Person
    string matrikelnummer, semester;

public:
    Student() { cout << "Student" << endl; }                                       // Standardkonstruktor
    Student(Student &t)                                                            // Kopierkonstruktor
        : person(t.person), matrikelnummer(t.matrikelnummer), semester(t.semester) // Initialisiert alle Instanzvariablen
    {
        cout << "Student--Init" << endl;
    }
    ~Student() { cout << "~Student" << endl; } // Destruktor
};

Student returnStudent(Student t) { return t; } // Gibt Variable t zurück

int main()
{
    Student s;        // Erzeugt Instanz von Student
    returnStudent(s); // Gibt erzeugte Instanz zurück
    return 0;
}
