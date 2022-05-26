#ifndef Rockets_HPP
#define Rockets_HPP
#include "ArtilleryUnit.hpp"

class Rockets : public ArtilleryUnit
{
    public:
    Rockets(double cost, double damage);
    void getDescription();
};
#endif