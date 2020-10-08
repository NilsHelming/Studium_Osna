#include <iostream>
using namespace std;

int laenge(char *str){ //str zeigt auf 'H' im Beispiel
  char *p_str=str;                  //p_str jetzt auch
  while(*p_str!='\0') {
      p_str++;
  }             //p_str zeigt nun auf '\0' im Beispiel
  return p_str-str;          //Differenz zweier Zeiger
}

int main() {
  char* text="Hallo";
  int textLaenge=laenge(text);
  cout << textLaenge << endl;

  return 0;
}
