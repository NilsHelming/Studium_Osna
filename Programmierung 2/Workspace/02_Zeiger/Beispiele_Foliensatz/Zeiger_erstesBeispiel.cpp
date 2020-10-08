// Deklaration eines (nicht initialisierten!)
// double-Zeigers und einer double-Variablen
double *a, b;

a=&b;    // a zeigt jetzt auf b
*a=5;    // b=5
(*a)++;  // b=6

// Ein Zeiger auf Zeiger
double **c = &a;
cout << *c << " " << **c;
// gibt die Adresse von b gefolgt von dem
// aktuellen Wert von b aus

//! Nicht initialisierte Zeiger sind gefaehrlich
// Im folgenden Beispiel wird ein zufaelliger
// Speicherbereich durch den int-Wert 5 ueberschrieben.
int *d; //erzeugt Speicher fuer die Zeigervariable d,
*d=5;   //aber nicht fuer die Adresse, auf die d zeigt!
//! Der weitere Verlauf dieses Programme ist jetzt
//! unvorhersehbar!
