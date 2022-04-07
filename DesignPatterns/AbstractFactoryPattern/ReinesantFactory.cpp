#include "ReinesantFactory.hpp"
#include "Riflemen.hpp"
#include "Cavalrymen.hpp"
#include "Cannon.hpp"
#include <iostream>
#include <stdlib>

ReinesantFactory::~ReinesantFactory() {}

MeleeUnit* ReinesantFactory::makeInfantry()
{
    return new Riflemen(5,3);
}

CavalryUnit* ReinesantFactory::makeCavalry()
{
    return new Cavalrymen(5,3);
}

ArtilleryUnit* ReinesantFactory::makeArtillery()
{
    return new Cannon(5,3);
}

AviationUnit* ReinesantFactory::makeAviation()
{
    cout<<"Error, you cannot create airplanes in the reinesant age!"<<endl;
    return nullptr;
}