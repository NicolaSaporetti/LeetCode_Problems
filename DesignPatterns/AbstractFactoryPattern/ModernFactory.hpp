#ifndef ModernFactory_HPP
#define ModernFactory_HPP
#include "MilitaryFactory.hpp"
#include <memory>
using namespace std;

class ModernFactory : public MilitaryFactory
{
    public:
    ~ModernFactory() override;
    unique_ptr<MeleeUnit> makeInfantry() override;
    unique_ptr<CavalryUnit> makeCavalry() override;
    unique_ptr<ArtilleryUnit> makeArtillery() override;
    unique_ptr<AviationUnit> makeAviation() override;
};
#endif