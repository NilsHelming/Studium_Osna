#pragma once

#include "Punkt.h"
#include "MetrikVerhalten.h"

class Metrik2D : public MetrikVerhalten{
public:
    double abstand(const Punkt&, const Punkt&);
};