//
// Created by Lukas on 18.12.2020.
//

#include "Punkt3D.h"
#include <string>
Punkt3D::Punkt3D(double _x, double _y, double _z): x(_x), y(_y), z(_z){};
std::string Punkt3D::toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}