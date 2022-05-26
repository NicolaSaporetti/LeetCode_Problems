#include "MedievalFactory.hpp"
#include "Swordmen.hpp"
#include "Knights.hpp"
#include <iostream>
#include <memory>
using namespace std;

MedievalFactory::~MedievalFactory() {}

unique_ptr<MeleeUnit> MedievalFactory::makeInfantry()
{
    return unique_ptr<MeleeUnit>(new Swordmen(3,2));
}

unique_ptr<CavalryUnit> MedievalFactory::makeCavalry()
{
    return unique_ptr<CavalryUnit>(new Knights(3,2));
}

unique_ptr<ArtilleryUnit> MedievalFactory::makeArtillery()
{
    cout<<"Error, you cannot create artillery in the medieval age!"<<endl;
    return nullptr;
}

unique_ptr<AviationUnit> MedievalFactory::makeAviation()
{
    cout<<"Error, you cannot create airplanes in the medieval age!!"<<endl;
    return nullptr;
}