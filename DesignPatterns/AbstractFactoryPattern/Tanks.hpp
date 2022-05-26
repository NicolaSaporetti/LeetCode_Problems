#ifndef Tanks_HPP
#define Tanks_HPP
#include "CavalryUnit.hpp"

class Tanks : public CavalryUnit
{
    public:
    Tanks(double cost, double damage);
    void getDescription();
};
#endif