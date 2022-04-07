#include "MeleeUnit.hpp"

class Riflemen : public MeleeUnit
{
    public:
    Riflemen(double cost, double damage);
    protected:
    void getDescription() override;
};