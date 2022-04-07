class MilitaryUnit
{
    public:
    MilitaryUnit(double cost, double damage);
    private:
    double cost;
    double damage;
    protected:
    virtual void getDescription() = 0;
};