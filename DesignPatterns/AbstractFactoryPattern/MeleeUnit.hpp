#include <MilitaryUnit.hpp>

class MeleeUnit : public MilitaryUnit
{
    public:
    MeleeUnit(double cost, double damage);
    protected:
    void getDescription() override;
};