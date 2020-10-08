#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int *x=new int; int *y=new int; int *z=new int;
   
  *x=1; *y=2; *z=3;
  cout << setw(2) << *x << *y << *z << endl;
  
  *z=*x;
  cout << setw(2) << *x << *y << *z << endl;
  
  y=x;
  cout << setw(2) << *x << *y << *z << endl;

  *x=4; *y=5; *z=6;
  cout << setw(2) << *x << *y << *z << endl;
  
  delete x; delete y; delete z;  
  return 0;
}
