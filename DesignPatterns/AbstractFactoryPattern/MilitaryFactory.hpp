#ifndef MilitaryFactory_HPP
#define MilitaryFactory_HPP
#include "MeleeUnit.hpp"
#include "CavalryUnit.hpp"
#include "ArtilleryUnit.hpp"
#include "AviationUnit.hpp"
#include <memory>
using namespace std;
class MilitaryFactory
{
    public:
    virtual ~MilitaryFactory() {};
    virtual unique_ptr<MeleeUnit> makeInfantry() = 0;
    virtual unique_ptr<CavalryUnit> makeCavalry() = 0;
    virtual unique_ptr<ArtilleryUnit> makeArtillery() = 0;
    virtual unique_ptr<AviationUnit> makeAviation() = 0;
};
#endif