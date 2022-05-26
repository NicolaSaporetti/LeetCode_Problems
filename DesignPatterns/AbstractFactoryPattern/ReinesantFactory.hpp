#ifndef ReinesantFactory_HPP
#define ReinesantFactory_HPP
#include "MilitaryFactory.hpp"
#include <memory>
using namespace std;

class ReinesantFactory : public MilitaryFactory
{
    public:
    ~ReinesantFactory() override;
    unique_ptr<MeleeUnit> makeInfantry() override;
    unique_ptr<CavalryUnit> makeCavalry() override;
    unique_ptr<ArtilleryUnit> makeArtillery() override;
    unique_ptr<AviationUnit> makeAviation() override;
};
#endif