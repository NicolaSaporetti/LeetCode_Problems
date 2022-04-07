#include <MilitaryUnit.hpp>

class AviationUnit
{
    public:
    AviationUnit(double cost, double damage);
    protected:
    void getDescription() override;
};