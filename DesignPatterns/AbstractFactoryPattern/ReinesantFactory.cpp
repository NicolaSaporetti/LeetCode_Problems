#include "ReinesantFactory.hpp"
#include "Riflemen.hpp"
#include "Cavalrymen.hpp"
#include "Cannon.hpp"
#include <iostream>
#include <memory>
using namespace std;

ReinesantFactory::~ReinesantFactory() {}

unique_ptr<MeleeUnit> ReinesantFactory::makeInfantry()
{
    return unique_ptr<MeleeUnit>(new Riflemen(5,3));
}

unique_ptr<CavalryUnit> ReinesantFactory::makeCavalry()
{
    return unique_ptr<CavalryUnit>(new Cavalrymen(5,3));
}

unique_ptr<ArtilleryUnit> ReinesantFactory::makeArtillery()
{
    return unique_ptr<ArtilleryUnit>(new Cannon(5,3));
}

unique_ptr<AviationUnit> ReinesantFactory::makeAviation()
{
    cout<<"Error, you cannot create airplanes in the reinesant age!"<<endl;
    return nullptr;
}