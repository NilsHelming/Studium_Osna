//
// Created by Lukas on 18.12.2020.
//

#ifndef INC_3_GEOBJECT_QUADER_H
#define INC_3_GEOBJECT_QUADER_H


#include "GeoObjekt.h"
#include "Punkt3D.h"

class Quader : public GeoObjekt{
private:
    Punkt3D luv;
    Punkt3D roh;
public:
    Quader(const Punkt3D&, const Punkt3D&);
    Quader();

    ~Quader();

    Quader& operator= (const Quader& src){
        if(this == &src)
            return *this;
        return assign(src);
    }

    void setzePunktLuv(const Punkt3D& p) {luv = p;}
    void setzePunktRoh(const Punkt3D& p) {roh = p;}
    std::string toString() const override;
    double inhalt() const override;

    virtual Quader* clone(){ return new Quader(*this); }
    virtual Quader& assign(const GeoObjekt& rhs);
};


#endif //INC_3_GEOBJECT_QUADER_H
