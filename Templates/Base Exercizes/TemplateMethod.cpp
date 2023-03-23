#include <iostream>
#include <vector>
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

    vector<int> v={1,2,3,4,5,6,1,2,3,1};
    cout<<"Number of 1 in vector: "<<count_if_template(begin(v),end(v),[](int elem){return elem==1;})<<endl;
}