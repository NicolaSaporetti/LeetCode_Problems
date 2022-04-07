#include <MilitaryFactory.hpp>

class ModernFactory
{
    public:
    ~ModernFactory() override;
    MeleeUnit* makeInfantry() override;
    CavalryUnit* makeCavalry() override;
    ArtilleryUnit* makeArtillery() override;
    AviationUnit* makeAviation() override;
};