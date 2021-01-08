#pragma once

#include <string>

#include "Punkt.h"
#include "MetrikVerhalten.h"
#include "GeoObjekt.h"

class Ball : public GeoObjekt  {
private:
    Punkt3D zentrum;
    double radius;
public:
    Ball(const Punkt3D&, const double&);
    Ball();

    ~Ball();

    Ball& operator= (const Ball&);

    void setzeZentrum(const Punkt3D&);
    void setzeRadius(double);

    std::string toString() const;
    double inhalt() const;
};