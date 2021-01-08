#pragma once

#include <string>

#include "Punkt2D.h"
#include "MetrikVerhalten.h"
#include "GeoObjekt.h"

class Rechteck : public GeoObjekt  {
private:
    Punkt2D lu;
    Punkt2D ro;
public:
    Rechteck(const Punkt2D&, const Punkt2D&);
    Rechteck();

    ~Rechteck();

    Rechteck& operator= (const Rechteck& src){
        if(this == &src)
            return *this;
        return assign(src);
    }

    void setzePunktLu(const Punkt2D&);
    void setzePunktRo(const Punkt2D&);
    std::string toString() const;
    double inhalt() const;

    virtual Rechteck* clone(){ return new Rechteck(*this); }
    virtual Rechteck& assign(const GeoObjekt& rhs);
};