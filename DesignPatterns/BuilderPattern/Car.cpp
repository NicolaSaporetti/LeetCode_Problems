#include "Car.hpp"
#include "Wheels.hpp"
#include "Seats.hpp"
#include "Engine.hpp"
#include "Doors.hpp"
#include "memory"
using namespace std;

void Car::installWheels(unique_ptr<Wheels> wheels)
{
    this->wheels = std::move(wheels);
}
    
void Car::installSeats(unique_ptr<Seats> seats)
{
    this->seats = std::move(seats);
}

void Car::installEngine(unique_ptr<Engine> engine)
{
    this->engine = std::move(engine);
}

void Car::installDoors(unique_ptr<Doors> doors)
{
    this->doors = std::move(doors);
}