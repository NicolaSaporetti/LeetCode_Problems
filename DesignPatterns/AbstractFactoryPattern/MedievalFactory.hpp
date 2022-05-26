#ifndef MedievalFactory_HPP
#define MedievalFactory_HPP
#include "MilitaryFactory.hpp"
#include <memory>

class MedievalFactory : public MilitaryFactory
{
    public:
    ~MedievalFactory() override;
    unique_ptr<MeleeUnit> makeInfantry() override;
    unique_ptr<CavalryUnit> makeCavalry() override;
    unique_ptr<ArtilleryUnit> makeArtillery() override;
    unique_ptr<AviationUnit> makeAviation() override;
};
#endif