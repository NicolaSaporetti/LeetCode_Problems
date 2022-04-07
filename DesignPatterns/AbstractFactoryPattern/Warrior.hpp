#include "MeleeUnit.hpp"

class Warrior : public MeleeUnit
{
    public:
    Warrior(double cost, double damage);
    protected:
    void getDescription() override;
};