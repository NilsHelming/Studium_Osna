/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: ausnahmebehandlung.cpp
 * 
 * Demonstration von Ausnahmebehandlungen
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>

using namespace std;

double kehrwert(int n)
{
    if (n == 0)
        throw string("Division durch Null"); // Wirft gegebenenfalls eine Ausnahme

    return 1. / n;
}

int main()
{
    int zahl;
    double inverse;

    do
    {
        cout << "Bitte eine ganze Zahl eingeben (1=Ende): ";
        cin >> zahl;
        try // Ausnahme kann hier auftreten
        {
            inverse = kehrwert(zahl);
            cout << inverse << endl;
        }
        catch (const string &s) // Ausnahme wird hier abgefangen
        {
            cout << s << endl
                 << "Bitte neuen Wert eingeben: ";
        }
    } while (zahl != 1);

    return 0;
}