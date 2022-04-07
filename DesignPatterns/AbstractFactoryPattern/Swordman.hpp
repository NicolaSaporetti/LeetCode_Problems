#include "MeleeUnit.hpp"

class Swordmen : public MeleeUnit
{
    public:
    Swordmen(double cost, double damage);
    protected:
    void getDescription() override;
};