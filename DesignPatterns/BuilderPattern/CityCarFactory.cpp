#include "CityCarFactory.hpp"
#include "Wheels.hpp"
#include "CityWheels.hpp"
#include "Seats.hpp"
#include "Engine.hpp"
#include "ElectricEngine.hpp"
#include "Doors.hpp"
#include <memory>
using namespace std;

CityCarFactory::~CityCarFactory() {};

unique_ptr<Car> CityCarFactory::buildCar()
{
    unique_ptr<Car> car = unique_ptr<Car>(new Car());
    car->installEngine(makeEngine());
    car->installWheels(makeWheels());
    car->installSeats(makeSeats());
    car->installDoors(makeDoors());
    return car;
}

unique_ptr<Wheels> CityCarFactory::makeWheels()
{
    return unique_ptr<Wheels>(new CityWheels());
}

unique_ptr<Seats> CityCarFactory::makeSeats()
{
    return unique_ptr<Seats>(new Seats());
}

unique_ptr<Engine> CityCarFactory::makeEngine()
{
    return unique_ptr<Engine>(new ElectricEngine(220, 600));
}

unique_ptr<Doors> CityCarFactory::makeDoors()
{
    return unique_ptr<Doors>(new Doors(4));
}