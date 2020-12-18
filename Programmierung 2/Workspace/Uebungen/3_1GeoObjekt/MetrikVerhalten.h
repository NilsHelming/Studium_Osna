#pragma once

#include "Punkt.h"

class MetrikVerhalten{
public:
    virtual double abstand(const Punkt&, const Punkt&) = 0;
};