/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: abstrakte_Klassen.cpp
 *
 * Definition einer abstrakten Klasse und einer
 * davon abgeleiteten konkreten Klasse
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include<iostream>
using namespace std;


// abstrakte Klasse
class B {
public:
 virtual void f()=0;// abstrakt durch rein virtuelle Methode
};           // (kann, muss aber nicht implementiert werden)


// konkrete Klasse  // muss die rein virtuellen Methoden
class U : public B {// implementieren
public:
 void f() { cout << "Durch diese Implementation"
                 << " bin ich eine konkrete Klasse"
                 << endl;
 }
};


/*
 * Demo
 */
int main() {
 //B b;          // geht nicht, da B abstrakt
 B *pb;          // geht
 
 //pb = new B;   // geht nicht, da B abstrakt
 pb = new U;     // geht
 
 pb->f();        // Aufruf von f im zugehoerigen
                 // dynamischen Typ U
 
 return 0;
}
