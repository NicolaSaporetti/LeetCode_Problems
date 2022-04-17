#ifndef CarFactory_HPP
#define CarFactory_HPP
#include "Car.hpp"
#include "Wheels.hpp"
#include "Seats.hpp"
#include "Engine.hpp"
#include "Doors.hpp"
#include <memory>
using namespace std;

class CarFactory
{
    public:
    virtual ~CarFactory() {};
    virtual unique_ptr<Car> buildCar() = 0;
    protected:
    virtual unique_ptr<Wheels> makeWheels() = 0;
    virtual unique_ptr<Seats> makeSeats() = 0;
    virtual unique_ptr<Engine> makeEngine() = 0;
    virtual unique_ptr<Doors> makeDoors() = 0;
};
#endif