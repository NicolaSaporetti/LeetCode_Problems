#include <MilitaryFactory.hpp>

class StoneAgeFactory
{
    public:
    ~StoneAgeFactory() override;
    MeleeUnit* makeInfantry() override;
    CavalryUnit* makeCavalry() override;
    ArtilleryUnit* makeArtillery() override;
    AviationUnit* makeAviation() override;
};