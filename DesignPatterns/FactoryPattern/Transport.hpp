class Transport
{
    public:
    virtual ~Transport();
    virtual void get_description();

    protected:
    double cost;
    double time;
};