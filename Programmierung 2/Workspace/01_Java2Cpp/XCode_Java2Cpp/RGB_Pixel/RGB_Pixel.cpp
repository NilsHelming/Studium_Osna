/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: RGB_Pixel.cpp
 *
 * Operatorueberladung am Beispiel von RGB-Pixel Operationen
 *
 * Quelle: OOP-Skript B. Lang, HS Osnabrueck (angepasst und ueberarbeitet)
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#include<iostream>
#include<iomanip>
using namespace std;

//
// Struktur zur Darstellung von RGB-Werten
struct RGB { // Farbwerte jeweils zwischen 0 und 255
 unsigned char red;
 unsigned char green;
 unsigned char blue;
};


//
// Prototypen der ueberladenen Operatorfunktionen

// binaerer symmetrischer Operator
RGB operator+(const RGB &left, const RGB &right);
//^--liefert Ergebnis         ^--Operanden als
//   als neuen Wert zurueck      konstante Referenzen

// binaerer unsymmetrischer Operator
RGB operator*(const RGB &left, const double &factor);
//^--Ergebnisrueckgabe        ^--Operanden als
//   als Wert                    konstante Referenzen

// ...(inline) Version fuer vertauschte Argumente
inline RGB operator*(const double &factor,const RGB &right)
{ return right*factor; }
//            ^--Aufruf von operator*(right,factor)

// Ausgabeoperator
ostream& operator<<(ostream &s,              const RGB &out);
//^--Rueckgabe ist   ^--Strom wird veraendert ^--muss als
//   Referenz auf       daher nicht als          konstante
//   veraenderten       konstante Referenz       Referenz
//   Ausgabestrom       uebergeben               uebergeben
//                                               werden

//Eingabeoperator
istream& operator>>(istream &s, RGB &in);
//                               ^--darf nicht als
//                                  konstante Referenz
//                                  uebergeben werden


//
// Anwendungsbeispiel
//
int main () {
 RGB pixel1 = {128,240, 17};
 RGB pixel2 = { 27,150,250};
 RGB resultPixel;
 resultPixel = pixel1 + pixel2;  //Aufruf von operator+(pixel1,pixel2) und
                                 //Zuweisung an Ergebnisvariable
                                 //(Strukturkopie)
 //resultPixel = operator+(pixel1,pixel2); //oder so
 cout << resultPixel << endl;    //Aufruf von operator<<(cout,resultPixel)
 
 resultPixel = pixel1*0.7;       //Aufruf von operator*(pixel1,0.7)
 cout << resultPixel << endl;
 
 cout << pixel1*-0.7             //Aufruf von
      << endl;                   //operator<<(cout,operator(pixel1,-0.7))
 
 resultPixel = 0.7*pixel1;       //Aufruf von operator*(0.7,pixel1)
 cout << resultPixel << endl;
 
 cout << "Bitte r,g,b mit Whitespace getrennt eingeben\n";
 cin >> resultPixel;
 cout << resultPixel << endl;
 
 return 0;
}

//
// Implementationen
//

//
// operator +
RGB operator+(const RGB &left, const RGB &right) {
 int value;
 RGB result;
 // rot
 value = left.red + right.red;
 if (value>255) result.red=255;
 else result.red=value;
 // gruen
 value = left.green + right.green;
 if (value>255) result.green=255;
 else result.green=value;
 // blau
 value = left.blue + right.blue;
 if (value>255) result.blue=255;
 else result.blue=value;
 
 return result;
}

//
// operator *
RGB operator*(const RGB &left, const double &factor){
 double value;
 RGB result;
 value = left.red * factor;
 if (value>255.0)    result.red = 255;
 else if (value<0.0) result.red = 0;
 else result.red = static_cast<unsigned char>(value);
 value = left.green * factor;
 if (value>255.0)    result.green = 255;
 else if (value<0.0) result.green = 0;
 else result.green = static_cast<unsigned char>(value);
 value = left.blue * factor;
 if (value>255.0)    result.blue = 255;
 else if (value<0.0) result.blue = 0;
 else result.blue = static_cast<unsigned char>(value);
 return result;
}

//
// operator<<
ostream& operator<<(ostream &s, const RGB &out) {
 s << "(R=" << setw(3) << int(out.red)
 << ",G=" << setw(3) << int(out.green)
 << ",B=" << setw(3) << int(out.blue)
 << ")" << flush;
 return s;         // Rueckgabe des verarbeiteten Stroms
}

//
// operator>>
istream& operator>>(istream &s, RGB &in) {
 int r,g,b;
 s >> r >> g >> b; //Eingabe als integer
                   //Fuer speziellere Formatvorgaben
                   //z.B. "(r,g,b)" oder Eingabepruefungen
                   //sollte in eine string-Variable gelesen
                   //werden. Daraus koennen dann die
                   //einzelnen Bausteine extrahiert werden
 
 in.red=r;         //konvertieren nach
 in.green=g;       //unsigned int
 in.blue=b;
 return s;         //Rueckgabe des verarbeiteten Stroms
}

