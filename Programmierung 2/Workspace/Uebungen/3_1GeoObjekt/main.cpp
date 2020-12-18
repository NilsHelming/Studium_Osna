#include <iostream>

#include "Punkt.h"
#include "Rechteck.h"

using namespace std;

int main() {
 cout << "Rechtecke" << endl;
 cout << "---------" << endl;
 cout << "statischer Test" << endl;
 Rechteck rechteck( Punkt2D(0,0), Punkt2D(2,1));
 cout << rechteck.toString() << endl;
 cout <<  rechteck.inhalt() << endl;
    return 0;
}