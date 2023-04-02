using namespace std;
#include <iostream>

template<typename... T>
struct outer
{
    template <T... args>
    struct inner{};
};

int main()
{
    outer<int,short,char[5]> a;
}