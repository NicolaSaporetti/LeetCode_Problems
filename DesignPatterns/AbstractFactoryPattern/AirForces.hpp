#include "AviationUnit.hpp"

class AirForces : public AviationUnit
{
    public:
    AirForces(double cost, double damage);
    protected:
    void getDescription() override;
};