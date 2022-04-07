#include "Transport.hpp"

class Boat : public Transport
{
    public:
    Boat();
    void get_description() override;
};