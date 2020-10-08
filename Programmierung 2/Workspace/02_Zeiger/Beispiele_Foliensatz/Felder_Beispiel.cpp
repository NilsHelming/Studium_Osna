#include <iostream>
using namespace std;

int main() {
 double quadratzahlen[10];
 for (int i=0; i<6; i++) quadratzahlen[i]=i*i;
 for (int i=0; i<10; i++)
  cout << "i=" << i << '\t'
       << "quadrat=" << quadratzahlen[i] << endl;
 return 0;
}
