using namespace std;
#include <cassert>

template<int... Ts>
struct Vector {};

//Primary
template<typename inpV, typename outV = Vector<>>
struct uniq;

//First and next equal
template<int i, int... tail, int... outTail>
struct uniq<Vector<i,i,tail...>, Vector<outTail...>>
{
    using type = typename uniq<Vector<i,tail...>,Vector<outTail...>>::type;
};

//First and next not-equal
template<int i, int... tail, int... outTail>
struct uniq<Vector<i,tail...>, Vector<outTail...>>
{
    using type = typename uniq<Vector<tail...>,Vector<outTail...,i>>::type;
};

//Nothing remains on input
template<typename outTail>
struct uniq<Vector<>, outTail>
{
    using type = outTail;
};

int main()
{
    static_assert(std::is_same_v<typename uniq<Vector<2,2,3,4,5,5,5,5,6,6>>::type, Vector<2,3,4,5,6>>);
    static_assert(std::is_same_v<typename uniq<Vector<2,3,4,5,6>>::type, Vector<2,3,4,5,6>>);
    static_assert(std::is_same_v<typename uniq<Vector<1,1,1,1,2,2,2,2,2,1,2,2,2,2,2,2>>::type, Vector<1,2,1,2>>);
}