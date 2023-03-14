using namespace std;
#include <cassert>

template <unsigned... sizes>
struct sum
{
    static constexpr int value = 0;
};

template<unsigned size, unsigned... sizes>
struct sum<size, sizes...>
{
    static constexpr int value = size + sum<sizes...>::value; 
};

int main()
{
    static_assert(sum<1,2>::value==3);
    static_assert(sum<1,1,1,0,0,0>::value==3);
    return 0;
}