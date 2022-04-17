#include <iostream>
#include <stdlib.h>
#include <memory>
#include "CarFactory.hpp"
#include "SportCarFactory.cpp"
#include "CityCarFactory.cpp"
#include "Car.cpp"
#include "Wheels.cpp"
#include "SportWheels.cpp"
#include "CityWheels.cpp"
#include "Seats.cpp"
#include "Engine.cpp"
#include "ElectricEngine.cpp"
#include "DieselEngine.cpp"
#include "Doors.cpp"

using namespace std;

int main()
{
    unique_ptr<CarFactory> factory = unique_ptr<CarFactory>(new CityCarFactory());
    unique_ptr<Car> car = factory->buildCar();
    factory = unique_ptr<CarFactory>(new SportCarFactory());
    car = factory->buildCar();

    return 0;
}