#ifndef Cannon_HPP
#define Cannon_HPP
#include "ArtilleryUnit.hpp"

class Cannon : public ArtilleryUnit
{
    public:
    Cannon(double cost, double damage);
    void getDescription();
};
#endif