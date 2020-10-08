#include <iostream>
#include <string>
using namespace std;
#include "rgb.h"

class Window {
protected:  
  int x0, y0, x1, y1;    
public:  // ^-- Eckpunktkoordinaten
  Window(int x,int y, int u, int v): x0(x),y0(y), x1(u), y1(v) {}
};

class ColoredWindow: public Window {
protected:
  RGB_Pixel c;     
public:  // ^-- Farbe
  ColoredWindow(int x,int y,int u,int v,RGB_Pixel _c): Window(x,y,u,v), c(_c) {}
  virtual string draw() const { return "Zeichne farbiges Fenster"; }
};

class FramedWindow: public ColoredWindow {
  RGB_Pixel f;     
public:  // ^-- Rahmenfarbe
   FramedWindow(int x,int y, int u,int v,RGB_Pixel _c, RGB_Pixel _f)
   : ColoredWindow(x,y,u,v,_c), f(_f) {}
  virtual string draw() const { return "Zeichne gerahmtes farbiges Fenster"; }
};

void display(ColoredWindow cw) { cout << cw.draw() << endl; }

int main() {
  RGB_Pixel red(255,0,0), blue(0,255,0);
  ColoredWindow cw(0,0,100,50,blue);
  FramedWindow fw(0,0,100,50,red,blue);
  display(cw); display(fw);
  return 0;
}
