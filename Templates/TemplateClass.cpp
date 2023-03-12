using namespace std;
#include "TemplateClass.hpp"
#include <iostream>

int main()
{
    A<int> myClass(4,5);
    cout<<myClass.get_sum()<<endl;

    A<double> myClass2(4,5);
    cout<<myClass2.get_sum()<<endl;
}