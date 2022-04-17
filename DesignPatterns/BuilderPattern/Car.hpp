#ifndef Car_HPP
#define Car_HPP
#include "Wheels.hpp"
#include "Seats.hpp"
#include "Engine.hpp"
#include "Doors.hpp"
#include "memory"
using namespace std;

class Car
{
    public:
    void installWheels(unique_ptr<Wheels> wheels);
    void installSeats(unique_ptr<Seats> seats);
    void installEngine(unique_ptr<Engine> engine);
    void installDoors(unique_ptr<Doors> doors);
    
    protected:
    unique_ptr<Wheels> wheels;
    unique_ptr<Seats> seats;
    unique_ptr<Engine> engine;
    unique_ptr<Doors> doors;
};
#endif