#include "SportCarFactory.hpp"
#include "Wheels.hpp"
#include "SportWheels.hpp"
#include "Seats.hpp"
#include "Engine.hpp"
#include "DieselEngine.hpp"
#include "Doors.hpp"
#include <memory>
using namespace std;

SportCarFactory::~SportCarFactory() {};

unique_ptr<Car> SportCarFactory::buildCar()
{
    unique_ptr<Car> car = unique_ptr<Car>(new Car());
    car->installEngine(makeEngine());
    car->installWheels(makeWheels());
    car->installSeats(makeSeats());
    car->installDoors(makeDoors());
    return car;
}

unique_ptr<Wheels> SportCarFactory::makeWheels()
{
    return unique_ptr<Wheels>(new SportWheels());
}

unique_ptr<Seats> SportCarFactory::makeSeats()
{
    return unique_ptr<Seats>(new Seats());
}

unique_ptr<Engine> SportCarFactory::makeEngine()
{
    return unique_ptr<Engine>(new DieselEngine(150, 600));
}

unique_ptr<Doors> SportCarFactory::makeDoors()
{
    return unique_ptr<Doors>(new Doors(4));
}