/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: Funktionsobjekt.cpp
 * 
 * Demonstration zur Ueberladung des ()-Operators einer Klasse
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Klasse zur Erzeugung von Zufallszahlen
 * Zu Demonstrationszwecken hier sowohl Vereinbarung als auch Implementation
 */
class Random
{
  long letzteZufallszahl; // "Gedaechtnis"
  // Klassen-Konstanten aus Park/Miller,
  // Random Number Generators, Good Ones are Hard to Find, 1988
  static const long a = 16807,
                    m = 2147483647,
                    q = m / a,
                    r = m % a;

public:
  Random(long seed = 314159) : letzteZufallszahl(seed) {} // Initialisierung

  long operator()()
  { // erzeugt neue Zufallszahl
    long gamma;
    gamma = a * (letzteZufallszahl % q) - r * (letzteZufallszahl / q);
    if (gamma > 0)
      letzteZufallszahl = gamma;
    else
      letzteZufallszahl = gamma + m;
    return letzteZufallszahl;
  }

  // Weitere Ueberladungen
  long operator()(long min, long max) // Zufallszahl innerhalb [min,max]
  {
    return min + (operator()()) % (max - min);
  }

  double operator()(double min, double max) // dasselbe fuer double-Werte
  {
    return min + static_cast<double>(operator()()) / m * (max - min);
  }
};

/*
 * Verwendungsbeispiel
 */
int main()
{
  Random rd(1234);             // Initialisierung eines Zufallszahlen-Objekts
  for (int i = 0; i < 10; i++) // Aufruf von operator()()
    cout << rd() % 1000 << " ";
  cout << endl;
  for (int i = 0; i < 10; i++) // Aufruf von operator()(long, long)
    cout << rd(50L, 100L) << " ";
  cout << endl;
  for (int i = 0; i < 10; i++) // Aufruf von operator(double, double)
    cout << setprecision(2) << rd(0., 1.) << " ";
  cout << endl;
}
