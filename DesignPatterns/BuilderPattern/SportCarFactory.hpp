#ifndef SportCarFactory_HPP
#define SportCarFactory_HPP
#include "Car.hpp"
#include "Wheels.hpp"
#include "Seats.hpp"
#include "Engine.hpp"
#include "Doors.hpp"
#include <memory>
using namespace std;

class SportCarFactory : public CarFactory
{
    public:
    virtual ~SportCarFactory();
    unique_ptr<Car> buildCar() override;
    protected:
    unique_ptr<Wheels> makeWheels() override;
    unique_ptr<Seats> makeSeats() override;
    unique_ptr<Engine> makeEngine() override;
    unique_ptr<Doors> makeDoors() override;
};
#endif