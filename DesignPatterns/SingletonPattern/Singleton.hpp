#ifndef Singleton_HPP
#define Singleton_HPP

#include "iostream"
using namespace std;

class Singleton
{
protected:
    Singleton(const string value);

    static Singleton* singleton;
    string value;

public:
    Singleton(Singleton &other) = delete;
    
    void operator=(const Singleton &) = delete;

    static Singleton *GetInstance(const string& value);

    void SomeBusinessLogic();

    string get_value();
};
#endif