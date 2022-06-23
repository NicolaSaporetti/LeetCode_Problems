#include "Singleton.hpp"
#include "iostream"
using namespace std;

Singleton::Singleton(const string value): value(value) {}

Singleton* Singleton::singleton = nullptr;

Singleton *Singleton::GetInstance(const std::string& value)
{
    if(singleton==nullptr){
        singleton = new Singleton(value);
    }
    return singleton;
}

void Singleton::SomeBusinessLogic()
{
    cout<<"Execute Business Logic"<<endl;
}

string Singleton::get_value()
{
    return value;
}