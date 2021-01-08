#include <string>

#include "Punkt2D.h"
#include "Metrik2D.h"
#include "GeoObjekt.h"
#include "Rechteck.h"

// class Rechteck : public GeoObjekt  {
// private:
//     Punkt2D lu;
//     Punkt2D ro;
// public:
//     Rechteck(const Punkt2D&, const Punkt2D&);

//     void setzePunktLu(const Punkt2D&);
//     void setzePunktRo(const Punkt2D&);
//     std::string toString() const;
//     double inhalt() const;
// };

Rechteck::Rechteck(const Punkt2D& _lu, const Punkt2D& _ro): lu(_lu), ro(_ro){
    this->metrik = new Metrik2D();
}
Rechteck::Rechteck(): lu(), ro(){
    this->metrik = new Metrik2D();
}

Rechteck::~Rechteck(){
    delete this->metrik;
}

Rechteck& Rechteck::assign(const GeoObjekt& rhs){
    const Rechteck* lhs = dynamic_cast<const Rechteck*>(&rhs);
    if (lhs == nullptr)
        return *this;

    GeoObjekt::assign(rhs);

    this->lu = lhs->lu;
    this->ro = lhs->ro;
    return *this;
}

void Rechteck::setzePunktLu(const Punkt2D& _lu){
    this->lu = _lu;
}
void Rechteck::setzePunktRo(const Punkt2D& _ro){
    this->ro = _ro;
}

std::string Rechteck::toString() const {
    return "Rechteck: [" + this->lu.toString() + ", " + this->ro.toString() +"]";
}

double Rechteck::inhalt() const{
    double l = this->lu.x, o = this->ro.y, r = this->ro.x, u =this->lu.y;

    double a = this->metrik->abstand(Punkt2D(l,u), Punkt2D(l,o));
    double b = this->metrik->abstand(Punkt2D(l,o), Punkt2D(r,o));

    return a*b;
}
