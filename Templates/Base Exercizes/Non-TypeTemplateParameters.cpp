#include "Variadic.hpp"
#include <cassert>
using namespace std;

template<typename T, size_t S>
class buffer
{
private:
    T data[S];
public:
    T& operator[](size_t const index) { return data[index];}
    T const & operator[](size_t const index) const { return data[index];}
};

int main()
{
    buffer<int,10> b1;
    buffer<int,2*5> b2;
    buffer<int,3*5> b3;
    static_assert(is_same_v<decltype(b1),decltype(b2)>);
    static_assert(!is_same_v<decltype(b1),decltype(b3)>);
}