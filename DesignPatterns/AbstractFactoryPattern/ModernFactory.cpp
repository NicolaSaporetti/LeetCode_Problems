#include "ModernFactory.hpp"
#include "ModernInfantry.hpp"
#include "Tanks.hpp"
#include "Rockets.hpp"
#include "AirForces.hpp"
#include <memory>
using namespace std;

ModernFactory::~ModernFactory() {}

unique_ptr<MeleeUnit> ModernFactory::makeInfantry()
{
    return unique_ptr<MeleeUnit>(new ModernInfantry(7,5));
}

unique_ptr<CavalryUnit> ModernFactory::makeCavalry()
{
    return unique_ptr<CavalryUnit>(new Tanks(7,5));
}

unique_ptr<ArtilleryUnit> ModernFactory::makeArtillery()
{
    return unique_ptr<ArtilleryUnit>(new Rockets(7,5));
}

unique_ptr<AviationUnit> ModernFactory::makeAviation()
{
    return unique_ptr<AviationUnit>(new AirForces(7,5));
}