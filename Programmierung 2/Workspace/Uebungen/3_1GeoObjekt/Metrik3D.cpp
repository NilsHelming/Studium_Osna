#include "Punkt3D.h"
#include "Metrik3D.h"

#include <cmath>

double Metrik3D::abstand(const Punkt& A, const Punkt& B){
    const Punkt3D* pA = dynamic_cast<const Punkt3D*>(&A);
    const Punkt3D* pB = dynamic_cast<const Punkt3D*>(&B);

    if(pA == nullptr || pB == nullptr)
        throw new std::string("Metrik2D mit Falschen Argumenten aufgerufen!");

    return std::sqrt(std::pow(pA->x - pB->x,2) + std::pow(pA->y - pB->y,2) + std::pow(pA->z - pB->z,2));
}