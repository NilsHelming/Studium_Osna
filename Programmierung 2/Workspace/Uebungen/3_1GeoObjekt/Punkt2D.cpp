#include <string>
#include "Punkt.h"

Punkt2D::Punkt2D(double _x, double _y): x(_x), y(_y){};
std::string Punkt2D::toString() const{
     return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
}