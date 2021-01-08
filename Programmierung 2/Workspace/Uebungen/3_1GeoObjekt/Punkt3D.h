//
// Created by Lukas on 18.12.2020.
//
#pragma once

#ifndef INC_3_GEOBJECT_PUNKT3D_H
#define INC_3_GEOBJECT_PUNKT3D_H

#include "Punkt.h"

class Punkt3D : public Punkt {
public:
    double x;
    double y;
    double z;
    std::string toString() const override;
    Punkt3D(double, double, double);
    Punkt3D(){x=0;y=0;z=0;};
};


#endif //INC_3_GEOBJECT_PUNKT3D_H
