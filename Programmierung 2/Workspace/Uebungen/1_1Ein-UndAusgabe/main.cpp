/**
 * Erstellen Sie in C++ folgendes Programm:
 * Lesen sie aus der Datei eingabe.txt zeilenweise die Werte aus
 * und schreiben diese formatiert in die Datei ausgabe.txt .
 * Die Formatierung soll ̈uber Manipulatoren erfolgen.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> ///Manipulatoren

using namespace std;


// ofstream: Stream class to write on files
// ifstream: Stream class to read from files
// fstream: Stream class to both read and write from/to files.


int main () {
    ifstream inFile("eingabe.txt");
    ofstream outFile("ausgabe.txt");

    int nNumber;
    double dDouble;
    string sString;

    int nIndex {0};

    while(inFile >> nNumber >> dDouble >> sString){
        nIndex++;

        outFile << nIndex << ". | "
            << setw(4)  << setfill('0') << right << hex << nNumber << " | "
            << setw(7)  << setfill('0') << left  << dDouble << " | "
            << setw(15) << setfill('-') << right << sString << " | "
            << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
