#pragma once

#include <string>

#include "Punkt.h"
#include "MetrikVerhalten.h"

class GeoObjekt {
protected:
    MetrikVerhalten* metrik = nullptr;
public:
    GeoObjekt& operator= (const GeoObjekt& src){
        if(this == &src)
            return *this;
        return assign(src);
    }

    virtual double inhalt() const = 0;
    virtual std::string toString() const = 0;

    virtual GeoObjekt* clone() = 0;
    virtual GeoObjekt& assign(const GeoObjekt&){ return *this; }
};