//
// Created by Lukas on 18.12.2020.
//
#pragma once

#include "Punkt.h"

class Punkt2D : public Punkt{
public:
    double x;
    double y;
    std::string toString() const;
    Punkt2D(double, double);
    Punkt2D(){x=0;y=0;};
};
