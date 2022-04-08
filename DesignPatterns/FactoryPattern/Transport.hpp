#ifndef Transport_HPP
#define Transport_HPP

class Transport
{
    public:
    Transport(double cost, double time);
    virtual ~Transport();
    virtual void get_description();

    protected:
    double cost;
    double time;
};
#endif