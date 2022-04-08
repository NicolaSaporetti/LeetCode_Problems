#ifndef StoneAgeFactory_HPP
#define StoneAgeFactory_HPP
#include "MilitaryFactory.hpp"
#include <memory>
using namespace std;
class StoneAgeFactory : public MilitaryFactory
{
    public:
    ~StoneAgeFactory() override;
    unique_ptr<MeleeUnit> makeInfantry() override;
    unique_ptr<CavalryUnit> makeCavalry() override;
    unique_ptr<ArtilleryUnit> makeArtillery() override;
    unique_ptr<AviationUnit> makeAviation() override;
};
#endif