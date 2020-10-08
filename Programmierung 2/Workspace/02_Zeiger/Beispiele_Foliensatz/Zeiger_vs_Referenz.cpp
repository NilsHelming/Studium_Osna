#include <iostream>
using namespace std;

void tauschMitZeigern(int* links, int* rechts) { 
  int hilf=*links;    // ^-- Call-by-reference
  *links=*rechts;     // bei jedem Wertzugriff muss
  *rechts=hilf;       // explizit dereferenziert werden
}

void tauschMitReferenzen(int& links, int& rechts) {
  int hilf=links;     //    ^-- Call-by-reference
  links=rechts;       // automatische Dereferenzierung
  rechts=hilf;
}

int main() {
  int a=5, b=6;
  tauschMitZeigern(&a, &b); // Es muessen zwingend die
                            // Adressen uebergeben werden
  cout << "a=" << a << " b=" << b << endl;  // a=6 b=5

  tauschMitReferenzen(a,b); // Werte werden automatisch
                            // an Formalparameter gebunden
                            //    ^--Referenzen, s.o.
  cout << "a=" << a << " b=" << b << endl;  // a=5 b=6
  return 0;
}
