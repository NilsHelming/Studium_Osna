#include <iostream>

#include "Punkt.h"
#include "Rechteck.h"
#include "Ball.h"

using namespace std;

int main() {
 cout << "Rechtecke" << endl;
 cout << "---------" << endl;
 cout << "statischer Test" << endl;
 Rechteck rechteck( Punkt2D(0,0), Punkt2D(2,1));
 cout << rechteck.toString() << " " << rechteck.inhalt() << endl;



 cout << endl;
 cout << "Baelle" << endl;
 cout << "---------" << endl;
 cout << "statischer Test" << endl;
 Ball ball( Punkt3D(1,1,1), 2);
 cout << ball.toString() << " " << ball.inhalt() << endl;
    return 0;
}