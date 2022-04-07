#include "ModernFactory.hpp"
#include "ModernInfantry.hpp"
#include "Tanks.hpp"
#include "Rockets.hpp"
#include "AirForces.hpp"

ModernFactory::~ModernFactory() {}

MeleeUnit* ModernFactory::makeInfantry()
{
    return new ModernInfantry(7,5);
}

CavalryUnit* ModernFactory::makeCavalry()
{
    return new Tanks(7,5);
}

ArtilleryUnit* ModernFactory::makeArtillery()
{
    return new Rockets(7,5);
}

AviationUnit* ModernFactory::makeAviation()
{
    return new AirForces(7,5);
}