using namespace std;
#include <iostream>

template<auto... x>
struct foo
{};

int main()
{
    foo<42,(short)42,345> a;
}