#include <iostream>
#include "TemplateMethod.hpp"
using namespace std;

int main()
{
    cout<<sum(1,2)<<endl;
    cout<<sum(1.0,2.0)<<endl;
    cout<<sum<int>(1,2)<<endl;
    cout<<sum<double>(1.0,2.0)<<endl;
    cout<<sum<int>(1.0,2.0)<<endl;
    cout<<sum<double>(1,2)<<endl;
    cout<<sum<string>("Hello "," world!")<<endl;
}