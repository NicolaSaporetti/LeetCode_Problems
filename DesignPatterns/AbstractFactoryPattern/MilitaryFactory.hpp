#include <MeleeUnit.hpp>
#include <CavalryUnit.hpp>
#include <ArtilleryUnit.hpp>
#include <AviationUnit.hpp>

class MilitaryFactory
{
    public:
    virtual ~MilitaryFactory();
    virtual MeleeUnit* makeInfantry() = 0;
    virtual CavalryUnit* makeCavalry() = 0;
    virtual ArtilleryUnit* makeArtillery() = 0;
    virtual AviationUnit* makeAviation() = 0;
};