#include "Wheels.hpp"
#include <iostream>

Wheels::Wheels(double width, double diameter): width(width), diameter(diameter)
{
    cout<<"Building wheel: width "<<width<<" diameter "<<diameter<<endl;
}