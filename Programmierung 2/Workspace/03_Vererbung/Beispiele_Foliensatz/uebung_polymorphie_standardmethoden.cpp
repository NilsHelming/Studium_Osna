#include<iostream>
using namespace std;

class K {
public:
  K() { cout << " K" << endl; }
 ~K() { cout << "~K" << endl; }
};

class B {
public:
  B() { cout << " B" << endl; }
 ~B() { cout << "~B" << endl; }
};

class U : public B {
  K  k1;
  K* k2;
public:
  U(): k2(new K) { cout << " U" << endl; }
 ~U() { cout << "~U" << endl; delete k2;  }
};

int main() {
  B* pb = new U;
  delete pb;

  return 0;
}
