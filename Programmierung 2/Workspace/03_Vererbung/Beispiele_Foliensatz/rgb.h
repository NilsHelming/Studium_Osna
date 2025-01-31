
class RGB_Pixel {    // Hilfsklasse fuer Farbwerte
  unsigned char R,G,B;
 public:
  RGB_Pixel() : R(0),G(0),B(0) {}
  RGB_Pixel(int Red,int Green, int Blue) : R(Red),G(Green),B(Blue) {}
  unsigned char Red  () const { return R; }
  unsigned char Green() const { return G; }
  unsigned char Blue () const { return B; }
  void Red  (int value) { R = value; }
  void Green(int value) { G = value; }
  void Blue (int value) { B = value; }
};
