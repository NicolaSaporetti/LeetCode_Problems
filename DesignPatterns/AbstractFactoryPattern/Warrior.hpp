#ifndef Warrior_HPP
#define Warrior_HPP
#include "MeleeUnit.hpp"

class Warrior : public MeleeUnit
{
    public:
    Warrior(double cost, double damage);
    void getDescription();
};
#endif