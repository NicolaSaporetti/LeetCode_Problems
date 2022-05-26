#ifndef Swordmen_HPP
#define Swordmen_HPP
#include "MeleeUnit.hpp"

class Swordmen : public MeleeUnit
{
    public:
    Swordmen(double cost, double damage);
    void getDescription();
};
#endif