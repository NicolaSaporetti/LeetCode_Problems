#include <MilitaryFactory.hpp>

class MedievalFactory
{
    public:
    ~MedievalFactory() override;
    MeleeUnit* makeInfantry() override;
    CavalryUnit* makeCavalry() override;
    ArtilleryUnit* makeArtillery() override;
    AviationUnit* makeAviation() override;
};