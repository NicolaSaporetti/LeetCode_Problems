#include <iostream>
#include <stdlib.h>
#include <memory>
#include "MilitaryFactory.hpp"
#include "StoneAgeFactory.cpp"
#include "MedievalFactory.cpp"
#include "ReinesantFactory.cpp"
#include "ModernFactory.cpp"
#include "MilitaryUnit.cpp"
#include "MeleeUnit.cpp"
#include "Warrior.cpp"
#include "Swordmen.cpp"
#include "Riflemen.cpp"
#include "ModernInfantry.cpp"
#include "CavalryUnit.cpp"
#include "Knights.cpp"
#include "Cavalrymen.cpp"
#include "Tanks.cpp"
#include "ArtilleryUnit.cpp"
#include "Cannon.cpp"
#include "Rockets.cpp"
#include "AviationUnit.cpp"
#include "AirForces.cpp"
using namespace std;

void createSoldiers(unique_ptr<MilitaryFactory>& militaryfactory)
{
    unique_ptr<MeleeUnit> melee = militaryfactory->makeInfantry();
    unique_ptr<CavalryUnit> cavalry = militaryfactory->makeCavalry();
    unique_ptr<ArtilleryUnit> artillery = militaryfactory->makeArtillery();
    unique_ptr<AviationUnit> air = militaryfactory->makeAviation();

    if(melee!=nullptr) melee->getDescription();
    if(cavalry!=nullptr) cavalry->getDescription();
    if(artillery!=nullptr) artillery->getDescription();
    if(air!=nullptr) air->getDescription();
}

int main() 
{
    int age[4] = {0,1,2,3};
    unique_ptr<MilitaryFactory> militaryfactory = nullptr;
    for(int i=0;i<4;i++)
    {
        switch(age[i])
        {
            case 0:
                militaryfactory = unique_ptr<MilitaryFactory>(new StoneAgeFactory());
                createSoldiers(militaryfactory);
                break;
            case 1:
                militaryfactory = unique_ptr<MilitaryFactory>(new MedievalFactory());
                createSoldiers(militaryfactory);
            break;
            case 2:
                militaryfactory = unique_ptr<MilitaryFactory>(new ReinesantFactory());
                createSoldiers(militaryfactory);
            break;
            case 3:
                militaryfactory = unique_ptr<MilitaryFactory>(new ModernFactory());
                createSoldiers(militaryfactory);
            break;
        }
    }

    return 0;
}