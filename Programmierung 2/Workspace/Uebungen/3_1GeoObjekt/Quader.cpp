//
// Created by Lukas on 18.12.2020.
//

#include "Quader.h"
#include "Metrik3D.h"

Quader::Quader(const Punkt3D& _luv, const Punkt3D& _roh): luv(_luv), roh(_roh){
    this->metrik = new Metrik3D();
}
Quader::Quader(): luv(), roh(){
    this->metrik = new Metrik3D();
}

Quader::~Quader(){
    delete this->metrik;
}

Quader& Quader::assign(const GeoObjekt& rhs){
    const Quader* lhs = dynamic_cast<const Quader*>(&rhs);
    if (lhs == nullptr)
        return *this;

    GeoObjekt::assign(rhs);

    this->luv = lhs->luv;
    this->roh = lhs->roh;
    return *this;
}

std::string Quader::toString() const {
    return "Quader: [" + luv.toString() + ", " + roh.toString() + "]";
}
// V = a*b*c
double Quader::inhalt() const {
    return (roh.x-luv.x)*(roh.y-luv.y)*(roh.z-luv.z);
}