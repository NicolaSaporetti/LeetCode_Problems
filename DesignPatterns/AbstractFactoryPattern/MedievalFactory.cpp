#include "MedievalFactory.hpp"
#include "Swordmen.hpp"
#include "Knights.hpp"
#include <iostream>
#include <stdlib>

MedievalFactory::~MedievalFactory() {}

MeleeUnit* MedievalFactory::makeInfantry()
{
    return new Swordmen(3,2);
}

CavalryUnit* MedievalFactory::makeCavalry()
{
    return new Knights(3,2);
}

ArtilleryUnit* MedievalFactory::makeArtillery()
{
    cout<<"Error, you cannot create artillery in the medieval age!"<<endl;
    return nullptr;
}

AviationUnit* MedievalFactory::makeAviation()
{
    cout<<"Error, you cannot create airplanes in the medieval age!!"<<endl;
    return nullptr;
}