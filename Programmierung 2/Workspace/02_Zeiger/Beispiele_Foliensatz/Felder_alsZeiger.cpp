int a[10];       // reserviert einen zusammenhaengenden
                 // Speicherbereich fuer 10 integer-Werte

// a ist ein (konstanter) Zeiger auf das erste Feldelement
// syntaktisch aequivalenter Typ:
int* const b {a};// hier erfolgt keine Speicherreservierung!

// Zugriff auf Feldelemente mittels des Indexoperators:
a[3] = 5; b[2] = 7;

