#include <iostream>
using namespace std;

class ParkingSystem {
private:
    int small;
    int med;
    int big;
public:
    ParkingSystem(int big, int medium, int small) {
        this->small = small;
        this->med = medium;
        this->big = big;
    }
    
    bool addCar(int carType) {
        switch(carType)
        {
            case 3:
                if(small>0)
                {
                    small --;
                    return true;
                }
                else return false;
            break;
            case 2:
                if(med>0)
                {
                    med --;
                    return true;
                }
                else return false;
            break;
            default:
                if(big>0)
                {
                    big --;
                    return true;
                }
                else return false;
            break;
        }
    }
};