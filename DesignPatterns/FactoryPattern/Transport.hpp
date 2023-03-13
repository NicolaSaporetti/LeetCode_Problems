#ifndef Transport_HPP
#define Transport_HPP

template<class T>
class Transport
{
    public:
    Transport(T cost, T time);
    virtual ~Transport();
    virtual void get_description();

    protected:
    T cost;
    T time;
};
#endif