#ifndef MilitaryUnit_HPP
#define MilitaryUnit_HPP

class MilitaryUnit
{
    public:
    MilitaryUnit(double cost, double damage);
    virtual void getDescription();
    private:
    double cost;
    double damage;
};
#endif