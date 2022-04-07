#include "MeleeUnit.hpp"

class ModernInfantry : public MeleeUnit
{
    public:
    ModernInfantry(double cost, double damage);
    protected:
    void getDescription() override;
};