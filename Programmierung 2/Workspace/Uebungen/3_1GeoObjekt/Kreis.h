//
// Created by Lukas on 18.12.2020.
//

#ifndef INC_3_GEOBJECT_KREIS_H
#define INC_3_GEOBJECT_KREIS_H


#include "GeoObjekt.h"
#include "Punkt2D.h"

class Kreis : public GeoObjekt{
private:
    double radius;
    Punkt2D zentrum;
public:
    Kreis(const Punkt2D&, const double&);
    Kreis();

    ~Kreis();

    Kreis& operator= (const Kreis& src){
        if(this == &src)
            return *this;
        return assign(src);
    }

    void setzeZentrum(const Punkt2D& p){zentrum = p;};
    void setzeRadius (double r) {radius = r;};
    std::string toString() const override;
    double inhalt() const override;

    virtual Kreis* clone(){ return new Kreis(*this); }
    virtual Kreis& assign(const GeoObjekt& rhs);
};


#endif //INC_3_GEOBJECT_KREIS_H
