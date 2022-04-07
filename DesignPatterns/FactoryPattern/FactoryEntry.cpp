#include <iostream>
#include <stdlib.h>
#include "Transport.hpp"
#include "LogisticsFactory.hpp"
#include "TruckFactory.hpp"
#include "BoatFactory.hpp"
using namespace std;

int main()
{
    LogisticsFactory* factory = new TruckFactory();
    Transport t1;

    for(int i=0;i<possibleNumbers.size(); i++)
    {
        cout<<"Sol: "<<possibleNumbers[i]<<endl;
    }
    return 0;
}