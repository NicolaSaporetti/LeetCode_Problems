#include "StoneAgeFactory.hpp"
#include "Warrior.hpp"
#include <iostream>
#include <stdlib>

StoneAgeFactory::~StoneAgeFactory() {}

MeleeUnit* StoneAgeFactory::makeInfantry()
{
    return new Warrior(2,1);
}

CavalryUnit* StoneAgeFactory::makeCavalry()
{
    cout<<"Error, you cannot create cavalry in the stone age!"<<endl;
    return nullptr;
}

ArtilleryUnit* StoneAgeFactory::makeArtillery()
{
    cout<<"Error, you cannot create artillery in the stone age!!"<<endl;
    return nullptr;
}

AviationUnit* StoneAgeFactory::makeAviation()
{
    cout<<"Error, you cannot create airplanes in the stone age!!!"<<endl;
    return nullptr;
}