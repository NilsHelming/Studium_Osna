#pragma once

#include <string>

#include "Punkt.h"
#include "MetrikVerhalten.h"

class GeoObjekt {
protected:
    MetrikVerhalten* metrik = nullptr;
public:
    virtual double inhalt() const = 0;
    virtual std::string toString() const = 0;
};