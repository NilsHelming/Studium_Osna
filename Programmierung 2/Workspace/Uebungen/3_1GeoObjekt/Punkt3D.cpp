#include <string>
#include "Punkt.h"

Punkt3D::Punkt3D(double _x, double _y, double _z): x(_x), y(_y), z(_z){};
std::string Punkt3D::toString() const{
     return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ")";
}