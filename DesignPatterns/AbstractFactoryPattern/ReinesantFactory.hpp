#include <MilitaryFactory.hpp>

class ReinesantFactory
{
    public:
    ~ReinesantFactory() override;
    MeleeUnit* makeInfantry() override;
    CavalryUnit* makeCavalry() override;
    ArtilleryUnit* makeArtillery() override;
    AviationUnit* makeAviation() override;
};