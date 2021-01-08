//
// Created by Lukas on 18.12.2020.
//

#include "Punkt2D.h"
using namespace std;


Punkt2D::Punkt2D(double _x, double _y): x(_x), y(_y){};
std::string Punkt2D::toString() const {
    return "(" + to_string(x) + ", " + to_string(y) + ")";
}