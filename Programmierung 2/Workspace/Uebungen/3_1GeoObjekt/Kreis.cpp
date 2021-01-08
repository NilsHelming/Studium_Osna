//
// Created by Lukas on 18.12.2020.
//

#include <math.h>
#include "Kreis.h"
#include "Punkt2D.h"
#include "Metrik2D.h"

float pi = 3.1415;

Kreis::Kreis(const Punkt2D& _zentrum, const double& _radius): zentrum(_zentrum), radius(_radius){
    this->metrik = new Metrik2D();
}
Kreis::Kreis(): zentrum(), radius(){
    this->metrik = new Metrik2D();
}

Kreis::~Kreis(){
    delete this->metrik;
}

Kreis& Kreis::assign(const GeoObjekt& rhs){
    const Kreis* lhs = dynamic_cast<const Kreis*>(&rhs);
    if (lhs == nullptr)
        return *this;

    GeoObjekt::assign(rhs);

    this->zentrum = lhs->zentrum;
    this->radius = lhs->radius;
    return *this;
}

std::string Kreis::toString() const {
    return "Kreis: [" + zentrum.toString() + ", " + std::to_string(radius) + "]";
}

double Kreis::inhalt() const {
    return pi*pow(radius, 2);
}