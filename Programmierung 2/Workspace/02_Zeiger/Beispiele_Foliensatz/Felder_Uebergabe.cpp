void zeigePalette(char *pFarbe, int anzFarben) {
  for(int i=0; i<anzFarben; i++) cout << pFarbe[i];
}

void aendereFeld(int *p, int anzZahlen) {
 p[anzZahlen-1] = -1; // call-by-reference fuer die
                      // Feldelemente
}

int main() {
 char farbe[3] = {'r','g','b'};
 zeigePalette(farbe,3);
 
 int zahlen[10] =         {0,1,2,3,4,5,6,7,8,9};
 aendereFeld(zahlen, 10); // 0,1,2,3,4,5,6,7,8,-1

 return 0;
}

