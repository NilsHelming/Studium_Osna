#pragma once

#include <string>

class Punkt{
private:
public:
    virtual std::string toString() const = 0;
};

class Punkt2D : public Punkt{
private:
public:
    double x;
    double y;

    Punkt2D(double _x = 0, double _y = 0);

    std::string toString() const;
};

class Punkt3D : public Punkt{
private:
public:
    double x;
    double y;
    double z;

    Punkt3D(double _x = 0, double _y = 0, double _z = 0);

    std::string toString() const;
};