#ifndef Cavalrymen_HPP
#define Cavalrymen_HPP
#include "CavalryUnit.hpp"

class Cavalrymen : public CavalryUnit
{
    public:
    Cavalrymen(double cost, double damage);
    void getDescription();
};
#endif