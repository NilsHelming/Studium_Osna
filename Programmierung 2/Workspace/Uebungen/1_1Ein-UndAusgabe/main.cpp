/**
 * Erstellen Sie in C++ folgendes Programm:
 * Lesen sie aus der Datei eingabe.txt zeilenweise die Werte aus
 * und schreiben diese formatiert in die Datei ausgabe.txt .
 * Die Formatierung soll ̈uber Manipulatoren erfolgen.
 */

#include <iostream>
#include <fstream>
#include <iomanip> ///Manipulatoren

using namespace std;


// ofstream: Stream class to write on files
// ifstream: Stream class to read from files
// fstream: Stream class to both read and write from/to files.


int main () {
    //in- and output streams - both represent files in the current workspace.
    ifstream inputDatei("C:\\Users\\nilsh\\OneDrive\\Dokumente\\Studium_Osna\\Programmierung 2\\Workspace\\Uebungen\\1_1Ein-UndAusgabe\\eingabe.txt");
    ofstream outputDatei("C:\\Users\\nilsh\\OneDrive\\Dokumente\\Studium_Osna\\Programmierung 2\\Workspace\\Uebungen\\1_1Ein-UndAusgabe\\ausgabe.txt");
    //fstream (the 3rd stream-type for files) would be able to read AND write.

    int spalte1;
    float spalte2;
    string spalte3;

    int i = 1;

    while(!(inputDatei >> spalte1 >> spalte2 >> spalte3).eof()){
        outputDatei << (i++) << ". | " << hex << setw(4) << setfill('0') << spalte1 << " | " << spalte2 << " | " << setw(15) << setfill('-') <<  spalte3 << " | "<< endl;
    }

    inputDatei.close();
    outputDatei.close();

    return 0;
}







    // //Entries of the inFile (int double string<endl>int double string<endl>...)
    // int nNumber;
    // double dDouble;
    // string sString;

    // //Counter for the current output-line
    // int nIndex {0};


 // while(inFile >> nNumber >> dDouble >> sString){ // While we still have a row to read
    //     nIndex++; //Keep track of the line we are currently on.

    //     //Write this line to the output file.
    //     outFile << nIndex << ". | "
    //         << setw(4)  << setfill('0') << right << hex << nNumber << " | "
    //         << setw(7)  << setfill('0') << left  << dDouble << " | "
    //         << setw(15) << setfill('-') << right << sString << " | "
    //         << endl;
    // }

    // inFile.close();
    // outFile.close();