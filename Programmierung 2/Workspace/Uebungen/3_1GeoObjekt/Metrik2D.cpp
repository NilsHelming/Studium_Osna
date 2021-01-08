#include "Punkt.h"
#include "Metrik2D.h"

#include <cmath>

double Metrik2D::abstand(const Punkt& A, const Punkt& B){
    const Punkt2D* pA = dynamic_cast<const Punkt2D*>(&A);
    const Punkt2D* pB = dynamic_cast<const Punkt2D*>(&B);

    if(pA == nullptr || pB == nullptr)
        throw new std::string("Metrik2D mit Falschen Argumenten aufgerufen!");

    return std::sqrt(std::pow(pA->x - pB->x,2) + std::pow(pA->y - pB->y,2));
}