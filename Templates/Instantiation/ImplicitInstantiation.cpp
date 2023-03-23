using namespace std;
#include <iostream>

template<typename T>
class control {};

template<typename T>
class button : public control<T> {};

int main()
{
    button<int>* p1 = new button<int>();
    control<int>* p2 = new button<int>();
}