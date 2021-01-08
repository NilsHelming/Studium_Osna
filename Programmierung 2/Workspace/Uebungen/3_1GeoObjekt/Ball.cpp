#include <string>
#include <cmath>

#include "Punkt3D.h"
#include "Metrik3D.h"
#include "GeoObjekt.h"
#include "Ball.h"

// class Ball : public GeoObjekt  {
// private:
//     double radius;
//     Punkt3D zentrum;
// public:
//     Ball(const Punkt2D&, const Punkt2D&);
//     Ball();

//     ~Ball();

//     Ball& operator= (const Ball&);

//     void setzeZentrum(const Punkt3D&);
//     void setzeRadius(double);

//     std::string toString() const;
//     double inhalt() const;
// };

Ball::Ball(const Punkt3D& _zentrum, const double& _radius) : zentrum(_zentrum), radius(_radius){
    this->metrik = new Metrik3D();
}
Ball::Ball(): zentrum(), radius(1){
    this->metrik = new Metrik3D();
}

Ball::~Ball(){
    delete this->metrik;
}

Ball& Ball::assign(const GeoObjekt& rhs){
    const Ball* lhs = dynamic_cast<const Ball*>(&rhs);
    if (lhs == nullptr)
        return *this;

    this->GeoObjekt::assign(rhs);

    this->zentrum = lhs->zentrum;
    this->radius = lhs->radius;
    return *this;
}

void Ball::setzeZentrum(const Punkt3D& _zentrum){
    this->zentrum = _zentrum;
}
void Ball::setzeRadius(double _radius){
    this->radius = _radius;
}

std::string Ball::toString() const {
    return "Ball: [" + this->zentrum.toString() + ", " + std::to_string(this->radius) +"]";
}

double Ball::inhalt() const{
    double pi = std::acos(-1);

    return std::pow(this->radius, 3) * pi * 4 / 3;
}
