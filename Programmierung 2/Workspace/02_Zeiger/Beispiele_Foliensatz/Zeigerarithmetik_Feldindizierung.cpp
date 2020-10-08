#include <iostream>
using namespace std;

int main() {
  int i, *pa,
      a[10]={0,1,2,3,4,5,6,7,8,9};
      
  pa=a;
  pa++;   /* zeigt nun auf a[1]       */
  *pa=-1; /* Element geaendert        */
  cout << a[5] << " " << *(a+5) << " "
       << *(pa+5) << " " << pa[5] << endl;
          /* Ausgabe: 5 5 6 6         */

  pa=a;   /* Zeiger zuruecksetzen     */
  for (int i=0; i<10; i++)
    cout << *(pa++) << " ";
          /* Ausgabe: 0 -1 2 3 .... 9 */

  return 0;
} 

  
