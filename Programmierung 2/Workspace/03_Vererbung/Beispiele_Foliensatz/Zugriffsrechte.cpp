/*
 * -----------------------------------------------------------------------------
 *
 * Beispielgeschuetztgramm: Zugriffsrechte.cpp
 *
 * Demonstration der Zugriffsrechte private, protected, public bei Vererbung
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */


class Basis {
private:
 int privat;
protected:
 int geschuetzt;
public:
 int offen;
 int gibPrivat() { return privat; }
 int gibGeschuetzt() { return geschuetzt; }
};

/// Zugriff aus abgeleiteter Klasse heraus
class Unter: public Basis {
public:
 int erlaubt()    { return offen; }
 //int Verboten() { return privat; }
 int dasGeht()    { return geschuetzt; }
 
 int dasGehtAuch(Unter u) { return u.geschuetzt; }
   //Datenabstraktion bzgl. Klasse Unter:
   //Innerhalb der Klasse Unter sind Zugriffe
   //auf saemtliche Klassenkomponenten erlaubt,
   //auf die die Klasse Unter das Zugriffsrecht
   //hat, unabhaengig vom konkreten Objekt
 
 //int GehtNicht(Basis b) { return b.geschuetzt; }
   //b gehoert einer anderen Klasse an!!
   //Damit ist der Zugriff von 'aussen' nicht
};//gestattet.

/// Zugriff von aussen
int main() {
 int i;
 Basis b;
 i = b.offen;
 i = b.gibGeschuetzt();
 i = b.gibPrivat();
 
 Unter u;
 i = u.offen;
 i = u.gibGeschuetzt();
 i = u.gibPrivat();
  
 return 0;
}
