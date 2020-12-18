#include "Punkt.h"
#include "Metrik2D.h"

#include <cmath>

double Metrik2D::abstand(const Punkt2D& A, const Punkt2D& B){
    return std::sqrt(std::pow(A.x - B.x,2) + std::pow(A.y - B.y,2));
}

double Metrik2D::abstand(const Punkt& A, const Punkt& B){
    throw new std::string("Metrik2D mit Falschen Argumenten aufgerufen!");
}