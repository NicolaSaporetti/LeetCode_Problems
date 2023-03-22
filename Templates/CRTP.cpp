using namespace std;
#include <iostream>

template<typename Derived>
class BaseInfantry
{
public:
    Derived& getDerived()
    {
        return static_cast<Derived&>(*this);
    }
    void printStrength()
    {
        getDerived().printStrength();
    }
};

class Oplites : public BaseInfantry<Oplites>
{
public:
    void printStrength()
    {
        cout<<"Strenght: 1"<<endl;
    }
};

class Swordman : public BaseInfantry<Swordman>
{
public:
    void printStrength()
    {
        cout<<"Strenght: 2"<<endl;
    }
};

class LineInfantry : public BaseInfantry<LineInfantry>
{
public:
    void printStrength()
    {
        cout<<"Strenght: 3"<<endl;
    }
};

class ModernInfantry : public BaseInfantry<ModernInfantry>
{
public:
    void printStrength()
    {
        cout<<"Strenght: 5"<<endl;
    }
};

template<typename T>
void printStrength(BaseInfantry<T>& infantry)
{
    infantry.printStrength();
}

int main()
{
    Oplites o;
    printStrength(o);
    Swordman s;
    printStrength(s);
    LineInfantry l;
    printStrength(l);
    ModernInfantry m;
    printStrength(m);
}