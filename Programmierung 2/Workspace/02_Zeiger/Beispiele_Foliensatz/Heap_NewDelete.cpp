/*
 * -----------------------------------------------------------------------------
 *
 * Beispielprogramm: newdelete.cpp
 *
 * Demonstration von new und delete und den damit verbundenen
 * Konstruktoraufrufen, bei der Speicheranforderung/Freigabe
 * von Klassenobjekten
 *
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <vector>
using namespace std;

class K {
  int n;
public:
  K()           : n(0)   { cout << "K "; }
  K(int _n)     : n(_n)  { cout << "K(" << n <<") "; }
  K(const K& k) : n(k.n) { cout << "KK(" << n <<") "; }
  ~K()                   { cout << "D(" << n <<") "; }
};


int main(){
 
  cout << "new K: ";
  K* pK_standard=new K;
  cout << endl;

  {
    cout << "new K_anweisungsblock: ";
    K* pK_anweisungsblock=new K;
    cout << endl;
  }


  cout << "new K(2): ";
  K* pK_zwei=new K(2);
  cout << endl;

  cout << "new K[5]: ";
  K* pK_feld=new K[5];
  cout << endl;

  cout << "vector<K> vK(5): ";
  vector<K> vK(5);
  cout << endl;

  cout << "delete pK_standard: ";
  delete pK_standard;
  cout << endl;

  cout << "delete pK_anweisungsblock: ";
  //delete pK_anweisungsblock;
  cout << "nicht mehr moeglich, Zeiger lebt nicht mehr" << endl;
  cout << "-->Speicherleck" << endl;

  cout << "delete pK_zwei: ";
  delete pK_zwei;
  cout << endl;

  cout << "delete pK_feld: ";
  delete [] pK_feld;
// delete pK_feld;   //--> Speicherleck
  cout << endl;

  cout << "Ende main ";
  return 0;
}
