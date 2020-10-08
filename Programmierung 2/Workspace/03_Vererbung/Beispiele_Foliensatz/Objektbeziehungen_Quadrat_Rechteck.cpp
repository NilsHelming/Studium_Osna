class Rechteck {
 int hoehe, breite;
public:
 Rechteck(int h, int b)
  : hoehe(h), breite(b) {}
 void neueHoehe (int h) {  hoehe=h; } // koennen unabhaengig
 void neueBreite(int b) { breite=b; } // veraendert werden
};

class Quadrat {
 Rechteck r;                // privates Attribut der Klasse
public:                     // zur Realisierung von Quadraten
 Quadrat(int seite)
  : r(seite,seite) {}       // Delegation an den Konstruktor
                            // der Klasse Rechteck
 void neueSeite (int neu) { // Delegation an Rechteck-Methoden
   r.neueHoehe(neu); r.neueBreite(neu);
 }
};
