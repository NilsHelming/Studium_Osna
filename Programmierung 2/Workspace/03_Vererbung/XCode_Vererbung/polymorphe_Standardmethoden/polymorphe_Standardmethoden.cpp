/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: polymorphe_Standardmethoden.cpp
 *
 * beispielhafte Implementation von polymorphen Standardmethoden
 * in einer Klassenhierarchie
 *
 *         B
 *      ---^---
 *      |     |
 *      U     V
 *
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
using namespace std;


/*
 * Basisklasse mit virtuellen Standardmethoden, soweit moeglich und sinnvoll
 */
class B {
protected:
  int x;
public:
  B(int _x): x(_x)                      {}
  virtual ~B()                          {}
  virtual B* clone()                    { cout << "  B::clone" << endl;
                                          return new B(*this);
                                        }
  B& operator=(const B& rhs)            { cout << "  B::operator=" << endl;
                                          if (this==&rhs) return *this;
                                          return assign(rhs); 
                                        }
  virtual B& assign(const B& rhs)       {
                                          cout << "  B::assign" << endl;
                                          x=rhs.x;
                                          return *this;
                                        }
  virtual void ichBinEin(const char* s) {
                                          cout << s
                                               << ": B-Objekt mit Datum |"
                                               << x << "|" << endl;
                                        }
};


/*
 * abgeleitete Klasse mit redefinierten Standardmethoden
 */
class U : public B {
  int y;
public:
  U(int _x, int _y): B(_x), y(_y) {}

  virtual ~U()                          {}

  virtual U* clone()                    { cout << "  U::clone" << endl;
                                          return new U(*this);
                                        }
  

  U& operator=(const U& rhs)            { cout << "  U::operator=" << endl;
                                          if (this==&rhs) return *this;
                                          return assign(rhs); 
                                        }
  virtual U& assign(const B& rhs)       {
                                          cout << "  U::assign" << endl;
					                                const U* pU=dynamic_cast<const U*>(&rhs);
                                          if (!pU) {
                                            cout << "  !!falscher Operand!!" << endl;
                                            return *this;
                                          }
                                          B::assign(rhs);
 					                                y = pU->y;
                                          return *this;
                                        }
  virtual void ichBinEin(const char* s) {
                                         cout << s
                                           << ": U-Objekt mit Daten |"
                                           << x << " " << y << "|" << endl;
                                        }
};


/*
 * Eine weitere abgeleitete Klasse mit redefinierten Standardmethoden
 */
class V : public B {
  int z;
public:
  V(int _x, int _z): B(_x), z(_z) {}

  virtual ~V()                          {}

  virtual V* clone()                    { cout << "  V::clone" << endl;
                                          return new V(*this);
                                        }

  V& operator=(const V& rhs)            { cout << "  V::operator=" << endl;
                                          if (this==&rhs) return *this;
                                          return assign(rhs); 
                                        }
  virtual V& assign(const B& rhs)       {
                                          cout << "  V::assign" << endl;
                                          const V* pV=dynamic_cast<const V*>(&rhs);
                                          if (!pV) {
                                           cout << "!! falscher Operand!" << endl;
                                                 return *this;
                                          }
                                          B::assign(rhs);
                                          z = pV->z;
                                          return *this;
                                        }
  virtual void ichBinEin(const char* s) {
                                         cout << s
                                           << ": V-Objekt mit Daten |"
                                           << x << " " << z << "|" << endl;
                                        }
};


/*
 * Demo
 */
int main() {

  //
  // Kopie in Wertesemantik
  U u(1,2);
  cout << "Kopierkonstruktor vom Objekt aus" << endl;
  cout << "Quelle: ";
  u.ichBinEin("u");
  cout << "Kopieroperation... " << endl;
  U uKopie(u);
  cout << "Kopiertes Objekt: ";
  uKopie.ichBinEin("uKopie");
  cin.get();

  //
  // (polymorphe) Kopie in Referenzsemantik
  V v(3,4);
  B* pb = &v, *pb2;    // Basisklassenzeiger
  cout << endl;
  cout << "Kopie mittels clone-Methode fuer Zeiger" << endl;
  cout << "Quelle: ";
  pb->ichBinEin("v");
  cout << "Kopieroperation... " << endl;  
  pb2=pb->clone();
  cout << "Kopiertes Objekt: ";
  pb2->ichBinEin("pb2");
  delete pb2; pb2=NULL; // Speicherfreigabe fuer pb2
  cin.get();


  //
  // Zuweisung in Wertesemantik
  U uNeu(5,6);
  cout << endl;
  cout << "Zuweisung vom Objekt aus" << endl;
  cout << "Zuweisungsziel: ";
  u.ichBinEin("u");
  cout << "Zuweisungsquelle: ";
  uNeu.ichBinEin("uNeu");
  cout << "Zuweisungen..." << endl;
  u=uNeu;
  cout << "Zuweisungsziel nach Zuweisung: ";
  u.ichBinEin("u");
  cin.get();

  //
  // Zuweisung in Referenzsemantik
  V vNeu(7,8);
  cout << endl;
  cout << "Zuweisung mittels Basisklassenzeiger" << endl;
  pb=&v;
  cout << "Zuweisungsziel: ";
  pb->ichBinEin("pb");
  cout << "Zuweisungsquelle: ";
  vNeu.ichBinEin("vNeu");
  cout << "Zuweisungen..." << endl;
  *pb = vNeu;
  cout << "Zuweisungsziel nach der Zuweisung: ";
  pb->ichBinEin("pb");
  cin.get();

  cout << endl;
  cout << "inkompatible Zuweisung mittels Basisklassenzeiger" << endl;
  cout << "Zuweisungsziel: ";
  pb->ichBinEin("pb");
  cout << "Zuweisungsquelle: ";
  u.ichBinEin("u");
  cout << "Zuweisungen..." << endl;
  *pb = u;
  cout << "Zuweisungsziel nach der Zuweisung: ";
  pb->ichBinEin("pb");
  

  return 0;
}
