#include "StoneAgeFactory.hpp"
#include "Warrior.hpp"
#include <iostream>
#include <memory>
using namespace std;

StoneAgeFactory::~StoneAgeFactory() {}

unique_ptr<MeleeUnit> StoneAgeFactory::makeInfantry()
{
    return unique_ptr<MeleeUnit>(new Warrior(2,1));
}

unique_ptr<CavalryUnit> StoneAgeFactory::makeCavalry()
{
    cout<<"Error, you cannot create cavalry in the stone age!"<<endl;
    return nullptr;
}

unique_ptr<ArtilleryUnit> StoneAgeFactory::makeArtillery()
{
    cout<<"Error, you cannot create artillery in the stone age!!"<<endl;
    return nullptr;
}

unique_ptr<AviationUnit> StoneAgeFactory::makeAviation()
{
    cout<<"Error, you cannot create airplanes in the stone age!!!"<<endl;
    return nullptr;
}